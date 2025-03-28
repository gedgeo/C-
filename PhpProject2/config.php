<?php
$host = "172.18.58.7"; // Adresse du serveur
$dbname = "Projet_Drone_2025_"; // Nom de la base de données
$username = "snir"; // Nom d'utilisateur MySQL (modifier si nécessaire)
$password = "snir"; // Mot de passe (laisser vide si pas de mot de passe)

try {
    $pdo = new PDO("mysql:host=$host;dbname=$dbname;charset=utf8", $username, $password);
    $pdo->setAttribute(PDO::ATTR_ERRMODE, PDO::ERRMODE_EXCEPTION);
} catch (PDOException $e) {
    die("Erreur de connexion à la base de données : " . $e->getMessage());
}


