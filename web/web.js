document.addEventListener('DOMContentLoaded', function() {
    const hamburger = document.querySelector('.hamburger');
    const wrapper = document.querySelector('.wrapper');

    hamburger.addEventListener('click', function() {
        wrapper.classList.toggle('collapse');
    });

    let essais = []; // Stocke les numéros des essais
    let reussites = []; // Stocke les réussites au fil du temps
    let echecs = []; // Stocke les échecs au fil du temps
    let compteur = 0; // Compteur d'essais

    document.querySelectorAll(".simulation-card").forEach(card => {
        card.addEventListener("click", function() {
            compteur++; // Nouvel essai
            const type = this.getAttribute("data-type");

            // Calculer les nouvelles valeurs
            let dernierReussite = reussites.length > 0 ? reussites[reussites.length - 1] : 0;
            let dernierEchec = echecs.length > 0 ? echecs[echecs.length - 1] : 0;

            if (type === "Reussite") {
                dernierReussite += 1;
            } else if (type === "Echec") {
                dernierEchec += 1;
            }

            essais.push(compteur);
            reussites.push(dernierReussite);
            echecs.push(dernierEchec);

            updateChart();
        });
    });

    function updateChart() {
        document.getElementById("chartContainer").style.display = "block";
        const ctx = document.getElementById("pieChart").getContext("2d");

        if (window.myChart) window.myChart.destroy();

        window.myChart = new Chart(ctx, {
            type: 'line',
            data: {
                labels: essais, // Affiche le nombre d'essais sur l'axe X
                datasets: [
                    {
                        label: 'Réussites',
                        data: reussites,
                        borderColor: 'green',
                        backgroundColor: 'rgba(0, 255, 0, 0.2)',
                        fill: false,
                        tension: 0.1
                    },
                    {
                        label: 'Échecs',
                        data: echecs,
                        borderColor: 'red',
                        backgroundColor: 'rgba(255, 0, 0, 0.2)',
                        fill: false,
                        tension: 0.1
                    }
                ]
            },
            options: {
                scales: {
                    x: {
                        title: {
                            display: true,
                            text: 'Nombre d\'essais'
                        }
                    },
                    y: {
                        beginAtZero: true,
                        title: {
                            display: true,
                            text: 'Cumul des résultats'
                        }
                    }
                }
            }
        });
    }
});

