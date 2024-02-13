// 沙尘暴     - Dust storm
// 高温       - High temperature
// 晴天       - Sunny day
// 高温沙尘暴 - Hot dust storm
let GameWeathers = ["Sunny day","High temperature","Dust storm", "Hot dust storm"];

let WeatherList = Array.from({ length: DayLimit }, function () {
    return new Array(MapLocations.length-1);
  });

  
function GetWeatherList(){
    for(let i = 0 ; i < DayLimit;i ++){
        for(let j = 0 ; j < MapLocations.length -1 ; j ++){
            WeatherList[i][j] = GetRandomInt(0,GameWeathers.length);
        }
    }
}