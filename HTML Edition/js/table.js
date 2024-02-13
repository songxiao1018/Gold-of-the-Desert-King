

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
            ChangeTableCell(i,j,"WeatherTable",GameWeathers[WeatherList[i][j-1]]);//
        }
    }
}
