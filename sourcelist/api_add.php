<?php 
/*
  $db['host'] = "localhost";  // DBサーバのurl
  $db['user'] = "daichi";
  $db['pass'] = "yoshitake";
  $db['dbname'] = "mai-archive";
*/


  $db['host'] = "mysql318.db.sakura.ne.jp";  // DBサーバのurl
  $db['user'] = "globalstudios";
  $db['pass'] = "ni-towakame";
  $db['dbname'] = "globalstudios_mai-archive";

  $mysqli = new mysqli($db['host'], $db['user'], $db['pass']);
  if ($mysqli->connect_errno) {
      print('<p>データベースへの接続に失敗しました。</p>' . $mysqli->connect_error);
      exit();
    }

  $mysqli->query("SET NAMES utf8");

  $mysqli->select_db($db['dbname']);

  $query = "insert into history(user_id, music_id, date, score, part, body, timing, expression, comment) values('" . $_GET["user"] . "', '" . $_GET["song"]. "', '" . $_GET["date"] . "', '" . $_GET["total"] . "', '" . $_GET["part"] . "' ,'" .  $_GET["body"] . "', '" . $_GET["timing"] . "', '" . $_GET["expression"] . "', '" . $_GET["comment"] . "');";

  $result = $mysqli->query($query);
  if (!$result) {
    print('クエリーが失敗しました。' . $mysqli->error);
    $mysqli->close();
    exit();
  }
  
  echo "1";
?>