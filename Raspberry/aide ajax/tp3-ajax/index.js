$(function () {

    $("#ajout_etudiant").on("click", function () {
        // requête ajax complète
        $.ajax({
            url: 'ajout_etudiant.php',
            type: 'POST',
            data: {
                nom: $("#ajout_etudiant_nom").val(),
                prenom: $("#ajout_etudiant_prenom").val()
            },
            dataType: 'text',
            success: function (resultat, statut) {
                if (resultat != "") alert(resultat); // erreur dans la requête sql
                else {
                    self.location.href = "index.php";
                }
            },
            // erreur dans la requête http
            error: function (resultat, statut, erreur) {
                console.log(resultat);
                alert(erreur);
            }
        });

        // requête ajax raccourcie

        /*$.post('ajout_etudiant.php', {
            nom: $("#ajout_etudiant_nom").val(),
            prenom: $("#ajout_etudiant_prenom").val(),
        },
            function (resultat, statut) {
                if (resultat != "") alert(resultat);
                else {
                    self.location.href = "index.php";
                }
            },
            'text');*/

    });



});
