<?php
$nom = $_POST['nom'];
$prenom = $_POST['prenom'];

include "connexion.php";

// ajout d'un étudiant
$req = $bdd->prepare('INSERT INTO etudiant (nom, prenom) VALUES(:nom, :prenom)');
$res = $req->execute(array('nom' => $nom,'prenom' => $prenom));

if ($res == false) {
    echo "\nPDOStatement::errorInfo():\n";
    $arr = $req->errorInfo();
    print_r($arr);
}
