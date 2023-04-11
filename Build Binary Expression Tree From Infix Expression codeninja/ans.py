from os import *
from sys import *
from collections import *
from math import *

# Following is the Binary Tree node structure:

class BinaryTreeNode :
    def __init__(self, data) :
        self.data = data
        self.left = None
        self.right = None
# input is a string of infix expression
# return root of the tree
def precedence(op):
    if op == '+' or op == '-':
        return 1
    if op == '*' or op == '/':
        return 2
    return 0
def infix2postfix(s):
    stack = []
    ans = []
    for char in s:
        if char == '(':
            stack.append(char)
        elif char == ')':
            while stack and stack[-1] != '(':
                ans.append(stack.pop())
            stack.pop() # pop the '('
        elif char == '+' or char == '-' or char == '*' or char == '/':
            # while the operand on top of the stack has greater precedence than the current operand
            while stack and stack[-1] != '(' and precedence(stack[-1]) >= precedence(char):
                ans.append(stack.pop())
            stack.append(char)
        else :
            ans.append(char)
    return ans
def postfix2ExprTree(s):
    stack = []
    for char in s:
        if char == '+' or char == '-' or char == '*' or char == '/':
            node = BinaryTreeNode(char)
            node.right = stack.pop()
            node.left = stack.pop()
            stack.append(node)
        else:
            node = BinaryTreeNode(char)
            stack.append(node)
    return stack.pop()

def binaryExpressionTree(s):
	# Write your code here.
    postfix = infix2postfix(s)
    root = postfix2ExprTree(postfix)
    return root        
    
# def main():
#     s = input()
#     binaryExpressionTree(s)

# if __name__ == "__main__":
#     main()