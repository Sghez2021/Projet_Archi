<html>

<head>
    <meta charset="utf-8" />
    <link rel="stylesheet" href="./style.css">
</head>

<body>
   <header>
    <h1>Bienvenue sur Meteor Tiles <img src="./meteor-solid.svg"/></h1>
 
   </header>

   <div class="container">

   <div class="score">
    <h2>Score :</h2>
   <?php  

    $file = fopen("test.txt", "r");
    if ($file == null) {
        echo "Fichier non exitant";
    } else {
        //Output lines until EOF is reached
        while (!feof($file)) {
            $line = fgets($file);
            echo $line . "<br>";
        }

        fclose($file);
    }

    ?>    
</div>

<div class="classement">
<h2>Classement :</h2>

    <?php
 $json = file_get_contents('records.json');
  
    // Decode the JSON file
    $json_data = json_decode($json,true);
      
    // Display data
    // print_r($json_data);
    for ($i = 0; $i <count($json_data) ; $i++) {
        echo "<p>" . $json_data[$i]["nom"] . "/". $json_data[$i]["pseudo"] . " : ";
        echo  $json_data[$i]["score"] . "</p>";
    }
    ?>

    
</div>

   </div>   

   
<footer>

</footer>

</body>

</html>