// Set default options to the values for HC3
function Highcharts3(H) {
    var buttonGradient;

    H.setOptions({
        colors: ['#2f7ed8', '#0d233a', '#8bbc21', '#910000', '#1aadce', '#492970',
            '#f28f43', '#77a1e5', '#c42525', '#a6c96a'],
        /* now ['#7cb5ec', '#434348', '#90ed7d', '#f7a35c', 
                '#8085e9', '#f15c80', '#e4d354', '#8085e8', '#8d4653', '#91e8e1']*/
        chart: {
            style: {
                fontFamily: '"Helvetica Neue", Helvetica, Arial, sans-serif'
            },
            borderRadius: 5 // now 0
        },
        title: {
            style: {
                color: '#274b6d', // now #333333
                fontSize: '16px' // now 18px
            }
        },
        subtitle: {
            style: {
                color: '#4d759e' // now #555555
            }
        },
        legend: {
            borderRadius: 5, // now 5
            borderWidth: 1, // now 0
            itemDistance: 8, // now 20
            itemStyle: {
                color: '#274b6d', // now #333333
                fontWeight: 'normal' // now bold
            },
            margin: 10, // now 20
            symbolRadius: 2 // now 0
        },
        tooltip: {
            backgroundColor: 'rgba(255,255,255,.85)', // now 'rgba(249, 249, 249, .85)'
            pointFormat: '<span style="color:{series.color}">{series.name}</span>: <b>{point.y}</b><br/>',
            // now '<span style="color:{series.color}">\u25CF</span> {series.name}: <b>{point.y}</b><br/>'
        },
        xAxis: {
            tickLength: 5, // now 10
            title: {
                style: {
                    color: '#4d759e', // now #707070
                    fontWeight: 'normal' // now bold
                }
            }
        },
        yAxis: {
            tickLength: 5, // now 10
            title: {
                style: {
                    color: '#4d759e', // now #707070
                    fontWeight: 'normal' // now bold
                }
            }
        },
        plotOptions: {
            series: {
                states: {
                    hover: {
                        halo: null
                    }
                }
            },
            line: {
                marker: {
                    enabled: true // now intelligent guess
                }
            }
        }
    });

    // Some other defaults depending on axis orientation
    H.Axis.prototype.defaultLeftAxisOptions.labels.x = -8; // now -15
    H.Axis.prototype.defaultRightAxisOptions.labels.x = 8; // now 15
    H.Axis.prototype.defaultBottomAxisOptions.labels.y = 14; // now 20
    H.Axis.prototype.defaultTopAxisOptions.labels.y = -5; // now -15


    // Highstock specific, this part can be removed if you're only using Highcharts
    buttonGradient = {
        linearGradient: {
            x1: 0,
            y1: 0,
            x2: 0,
            y2: 1
        },
        stops: [
            [0, '#FFF'],
            [1, '#CCC']
        ]
    };
    H.setOptions({
        navigator: {
            handles: {
                backgroundColor: '#FFF', // now #ebe7e8
                borderColor: '#666' // now #b2b1b6
            },
            margin: 10, // now 25,
            maskFill: 'rgba(255, 255, 255, 0.75)', // now rgba(128,179,236,0.3)
            maskInside: false, // now true
            outlineColor: '#444', // now #b2b1b6
            series: {
                fillOpacity: 0.4 // now 0.05
            }
        },
        rangeSelector: {
            buttonSpacing: 0, // now 5
            buttonTheme: {
                height: 16, // now 18
                padding: 1, // now 2
                stroke: '#68A',
                'stroke-width': 1, // now 0
            },
            inputBoxHeight: 16            
        },
        scrollbar: {
            barBackgroundColor: buttonGradient, // now #bfc8d1
            barBorderRadius: 2, // now 0
            barBorderColor: '#666', // naw #bfc8d1
            buttonBackgroundColor: buttonGradient, // now #ebe7e8
            buttonBorderColor: '#666', // now #bbb
            buttonBorderRadius: 2, // now 0
            trackBackgroundColor: { // now #eeeeee
                linearGradient: { x1: 0, y1: 0, x2: 0, y2: 1 },
                stops: [
                    [0, '#EEE'],
                    [1, '#FFF']
                ]
            },
            trackBorderColor: '#CCC' // #eeeeee
        }
    });
    
    // Special fall back to button defaults
    delete Highcharts.getOptions().rangeSelector.buttonTheme.fill;
    delete Highcharts.getOptions().rangeSelector.buttonTheme.states;
    
    // Need to calculate plotHigh & plotLow for all points in all series of "candlestick"!
    // These 2 values will be used but HighStock doesn't calculate them by default!
    // Use the wrapper mechanism provided by HighStock to override "translate()" to calculate these 2 values!
    H.wrap(H.seriesTypes.ohlc.prototype, 'translate', function(proceed) {
        proceed.apply(this, Array.prototype.slice.call(arguments, 1)); //super()!
        var series = this;
        var yAxis = series.yAxis;
        if (series.points && series.points instanceof Array) {
            series.points.forEach(function(point) {
                if (point.high !== null) {
                    point.plotHigh = yAxis.translate(point.high, 0, 1, 0, 1);
                }
                if (point.low !== null) {
                    point.plotLow = yAxis.translate(point.low, 0, 1, 0, 1);
                }
            });
        }
    });
    
    H.setOptions({
        global: {
            useUTC: false
        },
        lang: {
            thousandsSep: ''
        }
    });
};

// Call it
Highcharts3(Highcharts);

// Initialization of Highcharts 3 ends!
