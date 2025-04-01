<?php

require_once '../Modeles/Modele.php';

/**
 * Description of ModeleUsers
 *
 * @author pcruchet
 */
class ModeleUsers extends Modele {

    public function obtenirUtilisateurs() {
        try {
            $requete = $this->bdd->query("SELECT idUser, prenom from users;");
            $tabPrenoms = array();
            while ($ligne = $requete->fetch()) {
                array_push($tabPrenoms, array(
                    'prenom' => $ligne['prenom'],
                    'idUser' => $ligne['idUser'],
                        )
                );
            }
            $requete->closeCursor();
            return $tabPrenoms;
        } catch (PDOException $e) {
            print "Erreur !: " . $e->getMessage() . "<br/>";
            die();
        }
    }
}
