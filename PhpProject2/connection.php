<!DOCTYPE html>
<html>
    <head>
        <meta charset="UTF-8">
        <title>Formulaire de Connexion</title>
        <link rel="stylesheet" href="drone_css.css">
    </head>
    <body>
        <div class="body">
            <form class="form" action="web.html" method="post">
                <div id="heading">Connexion</div>
                <div class="field">
                    <span class="input-icon">
                        <!-- Icône SVG pour l'utilisateur -->
                        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-user"><path d="M20 21v-2a4 4 0 0 0-4-4H8a4 4 0 0 0-4 4v2"></path><circle cx="12" cy="7" r="4"></circle></svg>
                    </span>
                    <input type="text" class="input-field" placeholder="Nom d'utilisateur" required>
                </div>
                <div class="field">
                    <span class="input-icon">
                        <!-- Icône SVG pour le mot de passe -->
                        <svg xmlns="http://www.w3.org/2000/svg" width="24" height="24" viewBox="0 0 24 24" fill="none" stroke="currentColor" stroke-width="2" stroke-linecap="round" stroke-linejoin="round" class="feather feather-lock"><rect x="3" y="11" width="18" height="11" rx="2" ry="2"></rect><path d="M7 11V7a5 5 0 0 1 10 0v4"></path></svg>
                    </span>
                    <input type="password" class="input-field" placeholder="Mot de passe" required>
                </div>
                <div class="btn">
                    <button type="submit" class="button">Se connecter</button>
                </div>
            </form>
        </div>
    </body>
</html>
