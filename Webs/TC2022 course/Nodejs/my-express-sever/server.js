
const express = require("express");

const app = express();

app.get("/", function(request, response) {
  response.send("<h1>Hello World!</h1>");
});
app.get("/contact", function(req, res){
    res.send("Contact me at:hungbk1100@gmail.com");
});
app.get("/about", function(req, res){
    res.send("I am Hung, I love money");
});
app.get("/hobbies", function(req, res){
    res.send("<ul><li>Money</li><li>Money</li><li>Money</li></ul>");
});
app.listen(3000, function() {
  console.log("Server is running on port 3000");
});