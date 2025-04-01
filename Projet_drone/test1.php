<?php
// Inclusion du fichier de configuration
require_once 'Modeles/config.inc.php';

// Vérification de la connexion
if (!$conn) {
    die("Erreur de connexion : " . mysqli_connect_error());
}

// Récupérer les classes depuis la base de données
$sql = "SELECT id_classes, nom_classe FROM CLASSES";
$result = $conn->query($sql);

$options = "";

// Vérifier si la requête a renvoyé un résultat
if ($result === false) {
    die("Erreur SQL : " . $conn->error);
}

while ($row = $result->fetch_assoc()) {
    $options .= '<option value="' . htmlspecialchars($row['id_classes']) . '">' . htmlspecialchars($row['nom_classe']) . '</option>';
}

// Vérifier si le formulaire a été soumis
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    // Vérifier que les champs sont bien envoyés
    if (isset($_POST['nom'], $_POST['prenom'], $_POST['id_classes'])) {
        // Récupérer les valeurs du formulaire
        $nom = trim($_POST['nom']);
        $prenom = trim($_POST['prenom']);
        $id_classes = intval($_POST['id_classes']); // Sécurisation du paramètre ID

        // Vérifier que tous les champs sont remplis
        if (!empty($nom) && !empty($prenom) && !empty($id_classes)) {
            // Préparer la requête SQL
            $sql = "INSERT INTO UTILISATEURS (nom, prenom, id_classes) VALUES (?, ?, ?)";
            $stmt = $conn->prepare($sql);
            if ($stmt) {
                $stmt->bind_param("ssi", $nom, $prenom, $id_classes);

                // Exécution de la requête
                if ($stmt->execute()) {
                    echo "<p style='color:green;'>Nouvel enregistrement ajouté avec succès</p>";
                } else {
                    echo "<p style='color:red;'>Erreur lors de l'enregistrement : " . $stmt->error . "</p>";
                }
                // Fermer la requête préparée
                $stmt->close();
            } else {
                echo "<p style='color:red;'>Erreur de préparation de requête</p>";
            }
        } else {
            echo "<p style='color:red;'>Veuillez remplir tous les champs</p>";
        }
    } else {
        echo "<p style='color:red;'>Données manquantes dans le formulaire</p>";
    }
}

// Fermer la connexion à la base de données
$conn->close();
?>

<!-- Formulaire HTML -->
<form method="POST" action="">
    <label for="nom">Nom :</label>
    <input type="text" id="nom" name="nom" required><br><br>
    
    <label for="prenom">Prénom :</label>
    <input type="text" id="prenom" name="prenom" required><br><br>
    
    <label for="id_classes">Classe :</label>
    <select id="id_classes" name="id_classes" required>
        <option value="">Sélectionner une classe</option>
        <?= $options ?>
    </select><br><br>

    <button type="submit">Envoyer</button>
</form>
