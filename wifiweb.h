#pragma region WIFI

const char* PARAM_INPUT_1 = "output";
const char* PARAM_INPUT_2 = "state";
// Create AsyncWebServer object on port 80
AsyncWebServer server(80);
const char index_html[] PROGMEM = R"rawliteral(
<!DOCTYPE HTML>
<html>

<head>
    <title>ESP Web Server</title>
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <link rel="icon" href="data:,">
    <style>
        html {
            font-family: Arial;
            display: inline-block;
            text-align: center;
        }
        h2 {
            font-size: 3.0rem;
        }
        p {
            font-size: 3.0rem;
        }
        body {
            max-width: 600px;
            margin: 0px auto;
            padding-bottom: 25px;
        }
        .myslider {
            position: relative;
            display: inline-block;
        }
        .myslider input {width: 200px;}
        .band {display: none;}
        .selector, .selector option{height: 30px;}
    </style>
    <script>
      const all_controle_elements = ["adapt","brightness","band"]
      const allocation = {
         "1": ["adapt", "brightness"],
         "2": ["brightness"],
         "3": ["brightness"],
         "4": ["adapt","brightness","band"],
         "5": ["adapt","brightness"],
         "6": ["brightness"],
         "7": ["brightness"],
         "8": ["brightness"]
      }
        function visability(name, mode) {
            elements = document.getElementsByClassName(name)
            for (let i = 0; i < elements.length; i++) {
                elements[i].style.display = mode;
            }
        }
        function chooseProgram(element) {
            console.log(element)
            program = element.value
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/update?output=5&state=" + program, true);
            xhr.send();

            program = parseInt(program)

            for (let i = 0; i < all_controle_elements.length; i++) {
               const item = all_controle_elements[i];
               if (allocation[program].includes(item)) visability(item, "block");
               else visability(item, "none");
            }
        }
        function sendslider(element) {
            var xhr = new XMLHttpRequest();
            xhr.open("GET", "/update?output=" + element.id + "&state=" + element.value, true);
            xhr.send();
            console.log(element.value);
        }

        function slidervalueupdate(slider, out){
            output = document.getElementById(out)
            percent = ((slider.value - slider.min)/ (slider.max - slider.min)  * 100).toFixed() + '%%';
            if (out == "4h") res = "Brightness - " + percent
            else if (out == "6h") res = "Adaption - " + percent
            else if (out == "7h") res = "Auswahl Frequenzband - " + slider.value
            else if (out == "8h") res = "mover - " + slider.value
            output.innerHTML = res
        }

    </script> 

</head>

<body onload="chooseProgram(document.getElementById('mainselector'))">
    <h3>Das unglaubliche Lichtspektakel</h3>

    <h4>Choose Program</h4>

    <select id="mainselector" class="selector" onchange="chooseProgram(this);">
        <option value="1">VU Meter</option>
        <option value="3">Fire</option>
        <option value="2">Tunnel Square</option>
        <option value="4">Tunnel Square with Beat one Band</option>
        <option value="5">Tunnel Square with Beat all Bands</option>
        <option value="6">Text</option>
        <option value="7">GIF</option>
        <option value="8">Game</option>
    </select>

    <h4 id ="4h" class="brightness">Brightness - 20%%</h4>
    <label class="myslider brightness"><input type="range" min="0" max="255" value="150" oninput="slidervalueupdate(this,'4h')" onchange="sendslider(this)"
            id="4"></label>

    <h4 id ="6h" class="adapt">Adaption - 25%%</h4>
    <label class="myslider adapt"><input type="range" min="200" max="10000" value="2000" oninput="slidervalueupdate(this,'6h')" onchange="sendslider(this)"
            id="6"></label>

    <h4 id ="7h" class="band">Auswahl Frequenzband - 0</h4>
    <label class="myslider band"><input type="range" min="0" max="31" value="0" oninput="slidervalueupdate(this,'7h')" onchange="sendslider(this)"
        id="7"></label>

    <!-- <h4 id ="8h" class="mover">mover - 0</h4>
    <label class="myslider mover"><input type="range" min="0" max="28" value="14" oninput="slidervalueupdate(this,'8h')" onchange="sendslider(this)"
        id="8"></label> -->
</body>
</html>
)rawliteral";

//Replaces placeholder with button section in your web page
String processor(const String& var){
  //Serial.println(var);
  // if(var == "BUTTONPLACEHOLDER"){
  //   String buttons = "";
  //   buttons += "<h4>Output - GPIO 1</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"1\" " + outputState(1) + "><span class=\"slider\"></span></label>";
  //   buttons += "<h4>Output - GPIO 2</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"2\" " + outputState(2) + "><span class=\"slider\"></span></label>";
  //   buttons += "<h4>Output - GPIO 3</h4><label class=\"switch\"><input type=\"checkbox\" onchange=\"toggleCheckbox(this)\" id=\"3\" " + outputState(3) + "><span class=\"slider\"></span></label>";
  //   return buttons;
  // }
  // else if(var == "SCHIEBEREGLER"){
  //   String slider = "";
  //   slider += "<h4>Output - Brightness</h4><label class=\"myslider\"><input type=\"range\" min=\"0\" max=\"255\" value=\"50\" onchange=\"sendslider(this)\" id=\"4\"></label>";
  //   return slider;
  // }
  return String();
}

String outputState(int output){
  if(digitalRead(output)){
    return "checked";
  }
  else {
    return "";
  }
}
#pragma endregion WIFI