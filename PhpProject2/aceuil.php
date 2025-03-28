<!DOCTYPE html>
<html lang="fr">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Accueil - Simulateur de Drone</title>
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
                <div class="logo">
                    SIMULATEUR DE DRONE
                </div>
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
            <span class="title">Ajout d'eleve</span>
        </a></li>
    </ul>
</div>

        <div class="main_container">
            <div class="accueil">
                <h1>Bienvenue sur le Simulateur de Drone</h1>
                <p>Explorez notre simulateur pour apprendre et améliorer vos compétences de pilotage.</p>
                <div class="accueil-buttons">
                    <a href="historique.html" class="btn">Voir l'historique des vols</a>
                    <a href="stat.html" class="btn">Consulter les statistiques</a>
                    <a href="ajout.html" class="btn">Ajouter un élève</a>
                </div>
            </div>
        </div>
    </div>

    <script src="web.js"></script>
</body>
</html>
