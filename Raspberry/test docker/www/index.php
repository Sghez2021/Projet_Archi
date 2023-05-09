<?php
$page = $_SERVER['PHP_SELF'];
$sec = "5";
?>

<!DOCTYPE html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">
    <link rel="stylesheet" href="./style.css">
    <script src="https://code.jquery.com/jquery-1.12.4.js"></script>

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
            echo "<div class='affichagescoredanscore'>" . $line . "</div>";
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
        echo "<tr>" . "<td>" . $json_data[$i]["nom"] . "</td>";
        echo "<td>". $json_data[$i]["score"] ."</td>" ."</tr>";
    }
    
    ?>
    </tbody>
     
</table>
    
</div>

   </div> 

   <div class="boutonjeu">
   <?php

// Variable avec une valeur par défaut
$ma_variable = $_POST['etat'];

// Vérifier si une valeur a été définie dans la partie script
if (isset($_POST['etat'])) {
  // Modifier la variable avec la nouvelle valeur
  $ma_variable = $_POST['etat'];
}

// Si etat = 1 c false par contre si c -1 alors true
if ($ma_variable == 1 ){
// Le nom du fichier que vous souhaitez écrire
$fichier = 'play.txt';

// Le contenu que vous souhaitez écrire dans le fichier
$contenu = 'False';

// Écrire le contenu dans le fichier et remplacer l'ancien contenu
file_put_contents($fichier, $contenu, 0);
} else {
    // Le nom du fichier que vous souhaitez écrire
$fichier = 'play.txt';

// Le contenu que vous souhaitez écrire dans le fichier
$contenu = 'True';

// Écrire le contenu dans le fichier et remplacer l'ancien contenu
file_put_contents($fichier, $contenu, 0);
}



?>



   </div>  


</body>
<script>
let etat = 1;
$(function(){
     if(etat == 1 ){
        $('.boutonjeu').append($('<button>',{class : "lebout"}).text("Jouer"));
   }
})
$(document).on("click",('.lebout') ,function(){
    etat = etat * (-1);

    if(etat == 1 ){
        $(".lebout").text("Jouer")
   } else if (etat ==-1){
    $(".lebout").text("Stop")
   
   }
});



</script>

</html>
