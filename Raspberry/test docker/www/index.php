<!DOCTYPE html>

<head>
    <meta charset="utf-8" />
    <meta http-equiv="refresh" content="<?php echo $sec?>;URL='<?php echo $page?>'">
    <link rel="stylesheet" href="./style.css">
    <script src="https://code.jquery.com/jquery-1.12.4.js"></script>

</head>

<body>
    <?php
// $page = $_SERVER['PHP_SELF'];
// $sec = "10";
?>
   <header>
    <h1 class="titre">Bienvenue sur Meteor Tiles <img src="./meteor-solid.svg"/></h1>
 
   </header>

<input class="playername" type="text" placeholder="entrez votre nom de joueur">
<p id="result"></p>
<?php
$jsonFile = 'records.json';
$jsonData = file_get_contents($jsonFile);
$array = json_decode($jsonData, true);
if ($_SERVER['REQUEST_METHOD'] === 'POST') {
    $myVariable = $_POST['myVariable'];
     if (isset($_POST['myVariable'])) {
        // Récupérez la valeur de 'myVariable'
       
        // echo "succès";
        // Par exemple, affichez-la ou effectuez d'autres opérations
        $response = array('message' => 'Succès');
        echo json_encode($response);
        // Répondez au client avec une réponse appropriée
        // echo 'La requête POST a été traitée avec succès. Variable reçue : ' . $myVariable;
       
    } else {
        // Répondre avec une erreur si la requête n'est pas de type POST
        header('HTTP/1.1 405 Method Not Allowed');
        echo 'Cette URL n\'accepte que les requêtes POST.';
    }
    
  }
// $joueur = array(
//   'nom' => ,
//   'score' => ,
//   // Ajoutez d'autres attributs et valeurs selon vos besoins
// );

// $array[] = $joueur;

// $newJsonData = json_encode($array);

// file_put_contents($jsonFile, $newJsonData);

?>
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
<script src="index.js" async></script>

</html>
