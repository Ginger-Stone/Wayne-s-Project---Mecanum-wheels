$("button").click(function () {                            //if any button from the ".button" class is clicked      
    let dir = $(this).attr('id');
    let espIP = "192.168.0.105";                            //get this button id and store it inside the "p" variable.
    let nodeServer = "192.168.0.104";                            //get this button id and store it inside the "p" variable.
    if (dir === "forward") {
        dir = 1;
    } else if (dir === "right") {
        dir = 2;
    } else if (dir === "reverse") {
        dir = 3;
    } else if (dir === "left") {
        dir = 4;
    } else if (dir === "stop") {
        dir = 0;
    }
    console.log(dir);
    pin: dir                                                  //a dictionary contains the button id to get sent to the web server.
    $.get("http://" + nodeServer + ":5000/", {                       //then send a get request to the web server"http://192.168.1.4:80/" (":80" means port number 80) with some data in a form of dictionary {pin: dir} which is the button id. IMPORTANT NOTE: DON'T FORGET TO CHANGE THE IP ADDRESS WITH YOUR ESP8266 NEW IP ADDRESS.
        direction: dir,
    });
});