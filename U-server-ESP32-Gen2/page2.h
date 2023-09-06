const char* page2link = "/2";

static const char page2content[] PROGMEM = R"==(
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
 <head>
  <meta http-equiv="Content-Type" content="text/html; charset=utf-8">
  <title>Пример веб-страницы2</title>
  <!-- Подавить запрос браузера на favicon.ico -->
  <link rel="shortcut icon"type="image/x-icon" href="data:image/x-icon;,">
  <script src="favicon.js"></script>
  <!-- Подавить запрос браузера на favicon.ico -->
 </head>
 <body>
  <h1>Заголовок2</h1>
  <!-- Комментарий2 -->
  <p>Первый абзац2.</p>
  <p>Второй абзац2.</p>
 </body>
</html>
)==";
