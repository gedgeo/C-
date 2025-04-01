function afficherGraph() {
    var categories = ['Pommes', 'Bananes', 'Oranges'];
    var serie = [{
            name: 'Raymonde',
            data: [1, 0, 4]
        }];
    const chart = Highcharts.chart('graphe',
            {
                chart: {
                    type: 'bar'
                },
                title: {
                    text: 'Consommation de fruits'
                },
                xAxis: {
                    categories: categories
                },
                yAxis: {
                    title: 'Quantité'
                },
                series: serie
            });

}

function afficherGraphAjax() {
    $.getJSON('../Controleurs/Controleur.php',
            {
                action: 'getConsommations'
            })
            .done(function (donnees, stat, xhr) {
                var categories = donnees.categories;
                var tabSerie = donnees.series;
                const chart = Highcharts.chart('graphe',
                        {
                            chart: {
                                type: 'column'
                            },
                            title: {
                                text: 'Consommation de fruits'
                            },
                            xAxis: {
                                categories: categories
                            },
                            yAxis: {
                                title: 'Quantité'
                            },
                            series: tabSerie
                        });
            })
            .fail(function (xhr, text, error) {
                console.log("param : " + JSON.stringify(xhr));
            });
}

$(document).ready(function () {
    $('#menu').load('Menu.html');
    afficherGraphAjax();
});

