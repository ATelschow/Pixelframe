void Webserver(){
//WIFI

   // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }

  // Print ESP Local IP Address
  Serial.println(WiFi.localIP());

  // Route for root / web page
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", index_html, processor);
  });

   // Route for ota_interface / web page
  server.on("/ota", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send_P(200, "text/html", ota_html, processor);
  });

  // Send a GET request to <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
  server.on("/update", HTTP_GET, [] (AsyncWebServerRequest *request) {
    String inputMessage1;
    String inputMessage2;
   
    // GET input1 value on <ESP_IP>/update?output=<inputMessage1>&state=<inputMessage2>
    if (request->hasParam(PARAM_INPUT_1) && request->hasParam(PARAM_INPUT_2)) {
      inputMessage1 = request->getParam(PARAM_INPUT_1)->value();
      inputMessage2 = request->getParam(PARAM_INPUT_2)->value();
      digitalWrite(inputMessage1.toInt(), inputMessage2.toInt());

    }
    else {
      inputMessage1 = "No message sent";
      inputMessage2 = "No message sent";
    }

    Serial.print("GPIO: ");
    Serial.print(inputMessage1);
    Serial.print(" - Set to: ");
    Serial.println(inputMessage2);
    request->send(200, "text/plain", "OK");

    int i_inputMessage1 = inputMessage1.toInt();
    int i_inputMessage2 = inputMessage2.toInt();
    if ((i_inputMessage1 == 1 ) && (i_inputMessage2 == 1 )) (GPIO1 = 1);
    if ((i_inputMessage1 == 1 ) && (i_inputMessage2 == 0 )) (GPIO1 = 0);
    if ((i_inputMessage1 == 2 ) && (i_inputMessage2 == 1 )) (GPIO2 = 1);
    if ((i_inputMessage1 == 2 ) && (i_inputMessage2 == 0 )) (GPIO2 = 0);
    if ((i_inputMessage1 == 3 ) && (i_inputMessage2 == 1 )) (GPIO3 = 1);
    if ((i_inputMessage1 == 3 ) && (i_inputMessage2 == 0 )) (GPIO3 = 0);
    if (i_inputMessage1 == 4 ) (GPIO4 = i_inputMessage2);
    if (i_inputMessage1 == 5 ) (GPIO5 = i_inputMessage2);
    if (i_inputMessage1 == 6 ) (GPIO6 = i_inputMessage2);
    if (i_inputMessage1 == 7 ) (GPIO7 = i_inputMessage2);
    if (i_inputMessage1 == 8 ) (GPIO8 = i_inputMessage2);
    // Serial.print("GPIO1: ");
    // Serial.println(GPIO1);

   

  });

//   server.on("/otaupload", HTTP_POST, [](AsyncWebServerRequest *request){
//     // Check if the request has a file attached
//     if(request->hasParam("fileToUpload", true)){
//       AsyncWebParameter* fileParam = request->getParam("fileToUpload", true);

//       // Print the uploaded content directly
//       Serial.println("Uploaded content:");
//       Serial.println(fileParam->value());

//       // Send a response back to the client
//       request->send(200, "text/plain", "File content printed");
//     } else {
//       // No file or invalid request
//       request->send(400, "text/plain", "Invalid request");
//     }
//   });


  server.on("/otaupload", HTTP_POST, [](AsyncWebServerRequest * request) 
  {
    int paramsNr = request->params(); // number of params (e.g., 1)
    Serial.println(paramsNr);
    Serial.println();
    
    AsyncWebParameter * j = request->getParam(0); // 1st parameter
    Serial.print("Size: ");
    Serial.print(j->value());                     // value ^
    Serial.println();

    request->send(200);
  });
  // Start server
  server.begin();

}