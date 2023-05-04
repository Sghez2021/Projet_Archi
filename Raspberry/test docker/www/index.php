<html>

<head>
    <meta charset="utf-8" />
    <link rel="stylesheet" href="./style.css">
</head>

<body>
   <header>
    <h1 class="titre">Bienvenue sur Meteor Tiles <img src="./meteor-solid.svg"/></h1>
 
   </header>

   <div class="container">

   <div class="score">
    <h2>Score :</h2>
   <?php  

    $file = fopen("score.txt", "r");
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
<table>
    <thead>
        <tr>
          <th>Nom</th>
          <th>Pseudo </th>
          <th>Score </th>
    </tr>
    </thead>
    <tbody>
           <?php
 $json = file_get_contents('records.json');
  
    // Decode the JSON file
    $json_data = json_decode($json,true);
      
    // Display data
    // print_r($json_data);
    for ($i = 0; $i <count($json_data) ; $i++) {
        echo "<tr>" . "<td>" . $json_data[$i]["nom"] . "</td>". "<td>". $json_data[$i]["pseudo"] . " </td> ";
        echo "<td>". $json_data[$i]["score"] ."</td>" ."</tr>";
    }
    
    ?>
    </tbody>
     
</table>


    
</div>

   </div> 
   <div class="boutonjeu">
    <?php
    $etat= $_POST['etat'];
    if ($etat == 1){
        echo "<button> Jouer </button>";
    }else if($etat == -1){
        echo "<button> Stop </button>";

    }

?>
   </div>  


</body>
<script>

</script>

</html>