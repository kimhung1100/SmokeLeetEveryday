# create a crawl web page
#
 import requests
#
 # define a function to crawl web page
    def crawl_web(url):
        # get the web page
        response = requests.get(url)
        # return the web page
        return response.text

    # define a function to crawl web page
    def crawl_web_repeatedly(url): 
        while True:
            crawl_web(url)
            # ask user if he/she wants to play again
            user_input = input("Do you want to crawl again? (y/n): ")
            if user_input == "y": 
                continue
            else:
                break
#
    # call the function to crawl web page
    crawl_web_repeatedly("http://www.google.com")
#
#
#
#
#
#
#

