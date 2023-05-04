<?php
try {
    $bdd = new PDO('mysql:host=db;dbname=ngarric;charset=utf8', 'root', 'licinfo2020');
} catch (Exception $e) {
    die('Erreur : ' . $e->getMessage());
}
?>
