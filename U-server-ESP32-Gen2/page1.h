const char* page1link = "/";

static const char page1content[] PROGMEM =
R"==(
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <title>Пример веб-страницы1</title>
  <!-- Подавить запрос браузера на favicon.ico -->
  <link rel="shortcut icon"type="image/x-icon" href="data:image/x-icon;,">
  <script src="favicon.js"></script>
  <!-- Подавить запрос браузера на favicon.ico -->
 </head>
 <body>
  <h1>Hello, word! This is ESP32-CAM!</h1>
  <!-- Комментарий2 -->
  <p>Первый абзац1.</p>
  <p>Второй абзац1.</p>
  <p></p>
  <a href="/update">Update</a>
  <a href="/webserial">Serial</a>
 </body>
</html>
)==";
