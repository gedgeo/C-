<?php

// Inclusion du fichier de configuration
require_once '../Modeles/config.inc.php';

if (!$conn) {
    die("Erreur de connexion : " . mysqli_connect_error());
}

// Récupérer les classes depuis la base de données
$sql = "SELECT id_classes, nom_classe FROM CLASSES";
$result = $conn->query($sql);

$options = "";

if ($result === false) {
    die("Erreur SQL : " . $conn->error);
}

while ($row = $result->fetch_assoc()) {
    $options .= '<option value="' . htmlspecialchars($row['id_classes']) . '">' . htmlspecialchars($row['nom_classe']) . '</option>';
}

// Vérifier si le formulaire a été soumis
if ($_SERVER["REQUEST_METHOD"] == "POST") {
    if (isset($_POST['nom'], $_POST['prenom'], $_POST['id_classes'])) {
        $nom = trim($_POST['nom']);
        $prenom = trim($_POST['prenom']);
        $id_classes = intval($_POST['id_classes']);

        if (!empty($nom) && !empty($prenom) && !empty($id_classes)) {
            $sql = "INSERT INTO UTILISATEURS (nom, prenom, id_classes) VALUES (?, ?, ?)";
            $stmt = $conn->prepare($sql);
            if ($stmt) {
                $stmt->bind_param("ssi", $nom, $prenom, $id_classes);
                if ($stmt->execute()) {
                    echo "<p style='color:green;'>Nouvel enregistrement ajouté avec succès</p>";
                    echo "<script>window.location.reload();</script>"; // Recharge la page après soumission
                } else {
                    echo "<p style='color:red;'>Erreur lors de l'enregistrement : " . $stmt->error . "</p>";
                }
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

function afficherTableauUtilisateurs($conn)
{
    echo "<script>
        var oldTable = document.getElementById('table_utilisateurs');
        if (oldTable) oldTable.remove();
    </script>";

    $sql = "SELECT UTILISATEURS.nom, UTILISATEURS.prenom, CLASSES.nom_classe 
            FROM UTILISATEURS 
            JOIN CLASSES ON UTILISATEURS.id_classes = CLASSES.id_classes";
    $result = $conn->query($sql);

    if ($result && $result->num_rows > 0) {
        echo "<table id='table_utilisateurs' border='1'>
                <caption>Liste des utilisateurs</caption>
                <thead>
                    <tr>
                        <th scope='col'>Nom</th>
                        <th scope='col'>Prénom</th>
                        <th scope='col'>Classe</th>
                    </tr>
                </thead>
                <tbody>";

        while ($row = $result->fetch_assoc()) {
            echo "<tr>
                    <td>" . htmlspecialchars($row['nom']) . "</td>
                    <td>" . htmlspecialchars($row['prenom']) . "</td>
                    <td>" . htmlspecialchars($row['nom_classe']) . "</td>
                  </tr>";
        }

        echo "</tbody></table>";
    } else {
        echo "<p>Aucun utilisateur enregistré.</p>";
    }
}

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

    <button type="submit">Ajouter</button>
</form>

<?php
// Afficher le tableau des utilisateurs
afficherTableauUtilisateurs($conn);

// Fermer la connexion
$conn->close();
?>
