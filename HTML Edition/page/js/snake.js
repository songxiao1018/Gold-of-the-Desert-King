console.log('snake.js loaded');

// 得到Html的窗体对象
const canvas = document.getElementById('gameCanvas')
// Get the context of the canvas
const ctx = canvas.getContext('2d') // 设置2d对象

let scope = 20              // 范围
let step = 25               // 步长
let direction = "ArrowRight"  // 方向
let tail                       // 尾巴
let sleep = 500              // 刷新速度
let foodpoint              // 食物位置
let bodypoint = []         // 身体位置
let lastFrameTime = 0        // 上一帧时间

canvas.height = scope * step // 计算长
canvas.width = scope * step  // 计算宽


// 窗口初始化
function initCanvas() {
    ctx.rect(0, 0, canvas.width, canvas.height) // 设置大小
    ctx.fillStyle = "green" // 背景为绿色
    ctx.fill()              // 绘制命令

    // 绘制背景的格线
    for(let index = 0 ; index <= scope ; index ++){
        ctx.beginPath()                                // 开始绘制
        ctx.moveTo(index * step , 0)                   // 移动到（起始点
        ctx.lineTo(index * step , canvas.height )      // 移动到（结束点
        ctx.stroke()                                   // 绘制！
        ctx.moveTo(0 , index * step )
        ctx.lineTo(canvas.width , index * step )
        ctx.stroke()
    }
    console.log('Canvas loaded');
}

// 初始化蛇身
function initBody(){
    bodypoint = [{x:1,y:1},{x:2,y:1},{x:3,y:1}]
} 

// 绘制一个格子
function drawPoint(point,c){
    // 排除空对象
    if(point == null || point.x == undefined || point.y == undefined){
        return
    }
    // 取得一个位置
    let x = point.x * step
    let y = point.y * step
    // 开始绘制一个点
    ctx.beginPath()
    ctx.moveTo(x,y )
    ctx.lineTo(x + step ,y)
    ctx.lineTo(x+step,y + step)
    ctx.lineTo(x,y+step)
    ctx.lineTo(x,y)
    ctx.fillStyle = c;    // 设置填充颜色
    ctx.fill()            // 填充矩形
    ctx.stroke()          // 显示
}

// 绘制游戏界面
function drawGame(){
    // 将蛇的尾巴涂成绿色
    drawPoint(tail , "green")

    // 将蛇身体涂成红色
    bodypoint.forEach( point => {
        drawPoint(point,"red")
    })

    // 将食物涂成黄色
    drawPoint(foodpoint,"yellow")
}

// 获取随机值
function getRandomInt(min, max) {
    min = Math.ceil(min); // 向上取整
    max = Math.floor(max); // 向下取整
    return Math.floor(Math.random() * (max - min)) + min; // 含最大值，含最小值
}

// 获得随机的食物位置
function randomFood(){
    let isOnBody = true
    while(isOnBody){
        isOnBody = false
        // let x = Math.floor(Math.random()*scope)
        let x = getRandomInt(0,scope-1)
        let y = getRandomInt(0,scope-1)
        
        console.log('x:',x,'y:',y);

        // let res = bodypoint.filter( point => point.x == x && point.y == y) 
        // let res = bodypoint.find( point => point.x == x && point.y == y) 
        bodypoint.forEach( point => {
            if(point.x == x && point.y == y){
                isOnBody = true
            }
        })
        
        foodpoint = {x:x,y:y}
    }
}

// 返回按键的值
function keyPress() {
    document.addEventListener("keydown", function(event) {
        const key = event.key
        switch (key) {
            case "ArrowUp":
            case "ArrowDown":
            case "ArrowLeft":
            case "ArrowRight":
            case "w":
            case "s":
            case "a":
            case "d":
            case "W":
            case "S":
            case "A":
            case "D":
                direction = key // 使用更具描述性的值更新方向
                break
            // 可以根据需要添加其他案例
            default:
                // 对于不感兴趣的按键，不做处理
                break
        }
    });

    // function move(){
//     document.getElementById("body").onkeydown = function(event){
//         direction = event.keyCode
//     }
// }
}


// 移动蛇
function creep(){
    tail = bodypoint.shift()
    let head = {
        x : bodypoint[bodypoint.length - 1].x,
        y : bodypoint[bodypoint.length - 1].y
    }
    switch(direction){
        case "ArrowLeft" :
        case "a" :
        case "A" :
            head.x-- // 向左
            break
        case "ArrowUp" :
        case "w" :
        case "W" :
            head.y-- // 向上
            break
        case "ArrowRight" :
        case "d" :
        case "D" :
            head.x++ // 向右
            break
        case "ArrowDown" :
        case "s" :
        case "S" :
            head.y++ // 向下
            break
    }
    bodypoint.push(head)
    keyPress()
}

function eatFood(){
    let res = false
    let head = bodypoint[bodypoint.length - 1]

    switch(direction){
        case "ArrowLeft" :
        case "a" :
        case "A" :
            res = head.x - 1 == foodpoint.x && head.y == foodpoint.y
            break
        case "ArrowUp" :
        case "w" :
        case "W" :
            res = head.x == foodpoint.x && head.y - 1 == foodpoint.y
            break
        case "ArrowRight" :
        case "d" :
        case "D" :
            res = head.x + 1 == foodpoint.x && head.y == foodpoint.y
            break
        case "ArrowDown" :
        case "s" :
        case "S" :
            res = head.x == foodpoint.x && head.y + 1 == foodpoint.y
            break
    }

    if(res){
        bodypoint.push(foodpoint)
        drawPoint(foodpoint,"red")
        randomFood()
        // drawFood()
    }



}


// 游戏初始化
function initGame(){
    initCanvas()
    initBody()
    randomFood()
    drawGame()
    // drawFood()
}

function play(currentTime) {
    if (currentTime - lastFrameTime > sleep) {
        creep()
        eatFood()
        drawGame()
        lastFrameTime = currentTime
    }

    requestAnimationFrame(play)
}
// function play(){
//     creep()
//     drawGame()
//     setTimeout(play,sleep)
// }






initGame()
requestAnimationFrame(play);
