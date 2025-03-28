<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simulateur de Drone</title>
    <script src="https://kit.fontawesome.com/b99e675b6e.js"></script>
    <link rel="stylesheet" href="drone_css.css">
</head>
<body>
    <div class="wrapper">
        <div class="top_navbar">
            <div class="hamburger">
                <div class="one"></div>
                <div class="two"></div>
                <div class="three"></div>
            </div>
            <div class="top_menu">
                <div class="logo">SIMULATEUR DE DRONE</div>
                <ul>
                    <li><a href="#"><i class="fas fa-cog"></i></a></li>
                </ul>
            </div>
        </div>

        <div class="sidebar">
            <ul>
                <li><a href="acceuil.html">
                    <span class="icon"><i class="fas fa-bars"></i></span>
                    <span class="title">Accueil</span>
                </a></li>
                <li><a href="web.html" class="active">
                    <span class="icon"><i class="fas fa-history"></i></span>
                    <span class="title">Historique des vols</span>
                </a></li>
                <li><a href="stat.html">
                    <span class="icon"><i class="fas fa-chart-bar"></i></span>
                    <span class="title">Statistiques</span>
                </a></li>
                <li><a href="Ajout.html">
                    <span class="icon"><i class="fas fa-map"></i></span>
                    <span class="title">Ajout d'élève</span>
                </a></li>
            </ul>
        </div>

        <div class="main_container">
            <div class="item">
                <h2>Ajout d'élève</h2>
                <form id="ajout-eleve-form">
                    <label for="nom">Nom :</label>
                    <input type="text" id="nom" name="nom" required>

                    <label for="prenom">Prénom :</label>
                    <input type="text" id="prenom" name="prenom" required>

                    <label for="classe">Sélectionnez une classe :</label>
                    <select id="classe" name="id_classes">
                        <option value="1">Ciel2</option>
                        <option value="2">Classe 2</option>
                        <option value="3">Classe 3</option>
                        <option value="4">Classe 4</option>
                    </select>

                    <button class="Eleve" type="submit">Ajouter</button>
                </form>
                <div id="message"></div>
            </div>
        </div>
    </div>
 
    <script>
        document.getElementById("ajout-eleve-form").addEventListener("submit", function(event) {
            event.preventDefault();

            const nom = document.getElementById("nom").value;
            const prenom = document.getElementById("prenom").value;
            const id_classes = document.getElementById("classe").value;

            fetch("ajout_eleve.php", {
                method: "POST",
                headers: {
                    "Content-Type": "application/json"
                },
                body: JSON.stringify({ nom, prenom, id_classes })
            })
            .then(response => {
                if (!response.ok) {
                    throw new Error('Network response was not ok ' + response.statusText);
                }
                return response.json();
            })
            .then(data => {
                document.getElementById("message").innerText = data.message;
            })
            .catch(error => {
                document.getElementById("message").innerText = "Erreur lors de l'ajout: " + error.message;
            });
        });
    </script>  
    
</body>
</html>
<script>
error_reporting(E_ALL);
ini_set('display_errors', 1);

header("Content-Type: application/json");

if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    http_response_code(405);
    echo json_encode(["success" => false, "message" => "Méthode HTTP non autorisée"]);
    exit;
}

require "config.php"; // Connexion à la base de données

if (!isset($pdo)) {
    echo json_encode(["success" => false, "message" => "Erreur de connexion à la base de données"]);
    exit;
}

$data = json_decode(file_get_contents("php://input"), true);
if (!isset($data["nom"], $data["prenom"], $data["id_classes"])) {
    http_response_code(400);
    echo json_encode(["success" => false, "message" => "Données manquantes"]);
    exit;
}

try {
    $stmt = $pdo->prepare("INSERT INTO UTILISATEURS (nom, prenom, id_classes) VALUES (:nom, :prenom, :id_classes)");
    $stmt->execute([
        ":nom" => htmlspecialchars($data["nom"]),
        ":prenom" => htmlspecialchars($data["prenom"]),
        ":id_classes" => (int)$data["id_classes"]
    ]);
    echo json_encode(["success" => true, "message" => "Élève ajouté avec succès"]);
} catch (PDOException $e) {
    echo json_encode(["success" => false, "message" => "Erreur lors de l'ajout de l'élève"]);
}
</script>