//Websocekt variables
const url = "ws://localhost:9876/myWebsocket"
var mywsServer;

try{
    mywsServer = new WebSocket(url);
}catch(err){
    console.log('This never prints');
}
mywsServer.onerror = function (error) {
    console.log(error);
};
//DOM Elements
const myMessages = document.getElementById("messages")
const myInput = document.getElementById("message")
const sendBtn = document.getElementById("send")

console.log(myInput)

sendBtn.disabled = true
sendBtn.addEventListener("click", sendMsg, false)

//Sending message from client
function sendMsg() {
    const text = myInput.value
    msgGeneration(text, "Client")
    mywsServer.send(text)
}

//Creating DOM element to show received messages on browser page
function msgGeneration(msg, from) {
    const newMessage = document.createElement("h5")
    newMessage.innerText = `${from} says: ${msg}`
    myMessages.appendChild(newMessage)
}

//enabling send message when connection is open
mywsServer.onopen = function() {
    sendBtn.disabled = false
}

//handling message event
mywsServer.onmessage = function(event) {
    const { data } = event
    msgGeneration(data, "Server")
}
