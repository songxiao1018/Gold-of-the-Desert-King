
let DayLimit = 10;

// 获取随机值
function GetRandomInt(min, max) {
    min = Math.ceil(min); // 向上取整
    max = Math.floor(max); // 向下取整
    return Math.floor(Math.random() * (max - min)) + min; // 含最大值，含最小值
}
