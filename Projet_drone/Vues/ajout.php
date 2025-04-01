<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Simulateur de Drone</title>
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <script src="https://kit.fontawesome.com/b99e675b6e.js"></script>
</head>
<body>
    <div class="container-fluid">
        <nav class="navbar navbar-expand-lg navbar-dark bg-dark">
            <div class="container">
                <a class="navbar-brand" href="#">SIMULATEUR DE DRONE</a>
                <button class="navbar-toggler" type="button" data-bs-toggle="collapse" data-bs-target="#navbarNav">
                    <span class="navbar-toggler-icon"></span>
                </button>
                <div class="collapse navbar-collapse" id="navbarNav">
                    <ul class="navbar-nav ms-auto">
                        <li class="nav-item">
                            <a class="nav-link" href="#"><i class="fas fa-cog"></i></a>
                        </li>
                    </ul>
                </div>
            </div>
        </nav>

        <div class="row">
            <nav class="col-md-3 col-lg-2 d-md-block bg-light sidebar py-4">
                <ul class="nav flex-column">
                    <li class="nav-item"><a class="nav-link" href="acceuil.php"><i class="fas fa-bars"></i> Accueil</a></li>
                    <li class="nav-item"><a class="nav-link active" href="historique.php"><i class="fas fa-history"></i> Historique des vols</a></li>
                    <li class="nav-item"><a class="nav-link" href="stat.php"><i class="fas fa-chart-bar"></i> Statistiques</a></li>
                    <li class="nav-item"><a class="nav-link" href="ajout.php"><i class="fas fa-map"></i> Ajout d'élève</a></li>
                </ul>
            </nav>

            <main class="col-md-9 ms-sm-auto col-lg-10 px-md-4 py-4">
                <h2>Ajout d'élève</h2>
                <form id="ajout-eleve-form" class="mt-3">
                    <div class="mb-3">
                        <label for="nom" class="form-label">Nom :</label>
                        <input type="text" class="form-control" id="nom" name="nom" required>
                    </div>
                    <div class="mb-3">
                        <label for="prenom" class="form-label">Prénom :</label>
                        <input type="text" class="form-control" id="prenom" name="prenom" required>
                    </div>
                    <div class="mb-3">
                        <label for="classe" class="form-label">Sélectionnez une classe :</label>
                        <select class="form-select" id="classe" name="id_classes">
                        </select>
                    </div>
                    <button type="submit" class="btn btn-primary">Ajouter</button>
                </form>
                <div id="message" class="mt-3"></div>
            </main>
        </div>
    </div>

    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
    <script>
        document.getElementById("ajout-eleve-form").addEventListener("submit", function(event) {
            event.preventDefault();
            const nom = document.getElementById("nom").value;
            const prenom = document.getElementById("prenom").value;
            const id_classes = document.getElementById("classe").value;

            fetch("ajout_eleve.php", {
                method: "POST",
                headers: { "Content-Type": "application/json" },
                body: JSON.stringify({ nom, prenom, id_classes })
            })
            .then(response => response.json())
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
