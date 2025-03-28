<?php
$host = "172.18.58.7"; // Adresse du serveur
$dbname = "Projet_Drone_2025_"; // Nom de la base de données
$username = "snir"; // Nom d'utilisateur MySQL (modifier si nécessaire)
$password = "snir"; // Mot de passe (laisser vide si pas de mot de passe)

require_once __DIR__ . '/config.inc.php';

function connexionBdd() {
    try {
        $pdoOptions = array(PDO::ATTR_ERRMODE => PDO::ERRMODE_EXCEPTION);
        $bdd = new PDO('mysql:host=' . SERVBD . ';dbname=' . BASE, LOG, MDP, $pdoOptions);
        $bdd->exec("set names utf8");
        return $bdd;
    } catch (PDOException $e) {
        print "Erreur connexion bdd: " . $e->getMessage();
        die();
    }
}
