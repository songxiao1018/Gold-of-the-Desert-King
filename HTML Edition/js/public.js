// 沙漠 - Desert
// 村庄 - Village
// 王陵 - Mausoleum
// 大山 - Mountain
// 绿洲 - Oasis
let MapLocations = ["Day Num","Desert","Village","Mausoleum","Mountain","Oasis"];


// 沙尘暴     - Dust storm
// 高温       - High temperature
// 晴天       - Sunny day
// 高温沙尘暴 - Hot dust storm
let GameWeathers = ["Sunny day","High temperature","Dust storm", "Hot dust storm"];

// 食物 - "Food"
// 水 - "Water"
// 帐篷 - "Tent"
// 指南针 - "Compass"
// 钱 - "Money"
// 负载 - "Load"
// 黄金 - "Gold"
let GroupInformations = ["GroupID","Money","Load","Gold","Water","Food","Tent","Compass"]
//                  "Water","Food","Tent","Compass"
let BaseCampMoney = [25,10,400,100]
let VillageMoney = [50,20]
let ObjectWeight = [50,10,20,10] 

// 天数限制
let DayLimit = 20;

// 当前天数
let CurrentDay = 0;

// 天气列表
let WeatherList = Array.from({ length: DayLimit }, function () {
    return new Array(MapLocations.length-1);
});


// 获取随机值
function GetRandomInt(min, max) {
    min = Math.ceil(min); // 向上取整
    max = Math.floor(max); // 向下取整
    return Math.floor(Math.random() * (max - min)) + min; // 含最大值，含最小值
}

function CreateTable(tableRow, tableCol, tableName) {
    var table = document.getElementById(tableName);
    table.innerHTML = ""

    for (var i = 0; i < tableRow; i++) {
        var row = table.insertRow(i); // 创建行

        for (var j = 0; j < tableCol; j++) {
            var cell = row.insertCell(j); // 创建单元格
            cell.innerHTML = "None"; // 设置单元格内容
        }
    }
}

function ChangeTableCell(tableRow, tableCol, tableName , changeWord){
    var table = document.getElementById(tableName);
    var cell = table.rows[tableRow].cells[tableCol]; // 获取目标单元格
    cell.innerHTML = changeWord; // 修改单元格内容
}


function CreateWeatherTable(){
    CreateTable(DayLimit+1,MapLocations.length,"WeatherTable");

    // the first line
    for(let i = 0 ; i < MapLocations.length ; i ++){
        ChangeTableCell(0,i,"WeatherTable",MapLocations[i]);
    }

    for(let i = 1 ; i < DayLimit+1;i ++){
        ChangeTableCell(i,0,"WeatherTable","Day"+i);
        for(let j = 1 ; j < MapLocations.length ; j ++){
            ChangeTableCell(i,j,"WeatherTable",GameWeathers[WeatherList[i-1][j-1]]);//
        }
    }
}

function CreateOneDayWeather(){
    CreateTable(2,MapLocations.length,"NowWeatherTable");

    // the first line
    for(let i = 0 ; i < MapLocations.length ; i ++){
        ChangeTableCell(0,i,"NowWeatherTable",MapLocations[i]);
    }

    ChangeTableCell(1,0,"NowWeatherTable","Day"+(CurrentDay+1));
    for(let j = 1 ; j < MapLocations.length ; j ++){
        ChangeTableCell(1,j,"NowWeatherTable",GameWeathers[WeatherList[CurrentDay][j-1]]);//
    }
}


function GetWeatherList(){
    for(let i = 0 ; i < DayLimit;i ++){
        for(let j = 0 ; j < MapLocations.length -1 ; j ++){
            WeatherList[i][j] = GetRandomInt(0,GameWeathers.length);
        }
    }
}

function NextDayButton(){
    document.getElementById("NextDay").addEventListener("click", function() {
        CurrentDay++; // 每次点击增加1
        console.log(CurrentDay); // 输出当前变量值到控制台
    });
}

function GameInit(){
    GetWeatherList();
    CreateWeatherTable();
    CreateOneDayWeather();
    // NextDayButton();
}

GameInit();

document.getElementById("NextDay").addEventListener("click", function() {
    CurrentDay++; // 每次点击增加1
    console.log(CurrentDay); // 输出当前变量值到控制台
});

CreateOneDayWeather();

// while(true){
//     NextDayButton();
// }