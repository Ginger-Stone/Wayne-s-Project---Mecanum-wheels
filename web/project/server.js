// var http = require('http'); // 1 - Import Node.js core module

// var server = http.createServer(function (req, res) {   // 2 - creating server
//     console.log(req.url)
//     if (req.url == '/') { //check the URL of the current request
//         // set response header
//         res.writeHead(200, { 'Content-Type': 'text/html' }); 
        
//         // set response content    
//         res.write('<html><body><p>This is home Page.</p></body></html>');
//         res.end();
    
//     }

// });
const express = require('express');
const app = express();
const path = require("path");
const router = express.Router();

let data;

router.get('/', (req, res)=>{
    res.sendFile(path.join(__dirname+'/index.html'));
    data = req.query
    console.log(data);
})

router.get('/data', (req, res)=>{
    res.send(data)
    console.log(data);
})

app.use(express.static(path.join(__dirname,'css')));
app.use(express.static(path.join(__dirname,'js')));
app.use('/', router);
app.listen(process.env.port || 5000); //3 - listen for any incoming requests

console.log('Node.js web server at port 5000 is running..')