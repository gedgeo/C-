<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Accueil - Simulateur de Drone</title>
    
    <!-- Bootstrap 5 -->
    <link href="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/css/bootstrap.min.css" rel="stylesheet">
    <script src="https://kit.fontawesome.com/b99e675b6e.js" crossorigin="anonymous"></script>
    
    <!-- Fichier CSS -->
    <link href="Vues/libs/bootstrap/css/drone_css.css" rel="stylesheet" type="text/css"/>
</head>
<body>

    <!-- Barre latérale -->
    <div class="sidebar">
        <ul>
            <li><a href="acceuil.php"><i class="fas fa-home icon"></i> Accueil</a></li>
            <li><a href="historique.php" class="active"><i class="fas fa-history icon"></i> Historique des vols</a></li>
            <li><a href="stat.php"><i class="fas fa-chart-bar icon"></i> Statistiques</a></li>
            <li><a href="Ajout.php"><i class="fas fa-user-plus icon"></i> Ajout d'élève</a></li>
        </ul>
    </div>

    <!-- Contenu principal -->
    <div class="main-content">
        <div class="container">
            <h1 class="my-4 text-primary">Bienvenue sur le Simulateur de Drone</h1>
            <p>Explorez notre simulateur pour apprendre et améliorer vos compétences de pilotage.</p>
            
            <div class="accueil-buttons">
                <a href="historique.php" class="btn btn-primary"><i class="fas fa-history"></i> Voir l'historique des vols</a>
                <a href="stat.php" class="btn btn-success"><i class="fas fa-chart-bar"></i> Consulter les statistiques</a>
                <a href="ajout.php" class="btn btn-warning"><i class="fas fa-user-plus"></i> Ajouter un élève</a>
            </div>
        </div>
    </div>

    <!-- Bootstrap 5 JS -->
    <script src="https://cdn.jsdelivr.net/npm/bootstrap@5.3.0/dist/js/bootstrap.bundle.min.js"></script>
    <script src="web.js"></script>
</body>
</html>
