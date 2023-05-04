<!DOCTYPE html>
<html>
<link href="style.css" rel="stylesheet">
<script src="https://code.jquery.com/jquery-1.12.4.js"></script>
<script src="index.js"> </script>

<?php
include "connexion.php";

// on stocke les données dont on aura besoin dans des tableaux
$reponse = $bdd->query('SELECT *  FROM etudiant');
while ($donnees = $reponse->fetch()) {
    $tab_nom[$donnees['id_etudiant']] = $donnees['nom'];
    $tab_prenom[$donnees['id_etudiant']] = $donnees['prenom'];
}
?>

<head>
    <meta charset="UTF-8">
    <title>Premier programme avec du Php</title>
</head>

<body>
    <h1>Liste des étudiants</h1>
    <?php
    // affichage du tableau
    echo '<TABLE cellpadding=3 border=2>';
    echo '<FONT size="+2"><tr><th>Nom</th><th>Prénom</th><th></th></tr>';
    foreach ($tab_nom as $id_etudiant => $nom) {
        echo '<tr><td>'.$nom . '</td><td>' . $tab_prenom[$id_etudiant].'</td><td><button >Supprimer</button></td></tr>';
    }

    // ligne d'ajout d'un étudiant
    echo '<tr><td><input id="ajout_etudiant_nom" type=text></td><td><input id="ajout_etudiant_prenom" type=text></td><td><button id="ajout_etudiant" >Ajout</button></td></tr>';

    echo '</TABLE>';

    ?>
</body>

</html>