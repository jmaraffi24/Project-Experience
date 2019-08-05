/*
 * fifteen.js
 * CSCI 4300
 * Project 4
 * Team Name: HereToMakeLinks
 * Team Members: Mahdi Ghafouri, James Gong, Jacob Maraffi
 * This file "fifteen.js" contains all the javascript for the fifteen tile
 * sliding puzzle game for P4 in CSCI 4300 Web Programming.
 */

//start the game when the DOM has completed loading
document.addEventListener("DOMContentLoaded", puzzle);

function puzzle(){
    //creating a data structure to hold the positions of the tiles
    var parentX = document.querySelector(".puzzlepiece").clientHeight;
    //setting the base distance between each tile
    var baseDistance = 105;
    //creating a "map" of all the tiles
    var tileMap = {
        /*
         * num: the number identifier for each tile (constant)
         * pos: the position of the tile in the puzzle (changes)
         * top: column number of the tile (changes)
         * left: row number of the tile (changes)
         */
        //1/15 tiles
        1: {
            num: 1,
            pos: 1,
            top: 0,
            left: 0
        },
        //2/15 tiles
        2: {
            num: 2,
            pos: 2,
            top: 0,
            left: baseDistance
        },
        //3/15 tiles
        3: {
            num: 3,
            pos: 3,
            top: 0,
            left: baseDistance * 2
        },
        //4/15 tiles
        4: {
            num: 4,
            pos: 4,
            top: 0,
            left: baseDistance * 3
        },
        //END of first row
        //5/15 tiles
        5: {
            num: 5,
            pos: 5,
            top: baseDistance,
            left: 0
        },
        //6/15 tiles
        6: {
            num: 6,
            pos: 6,
            top: baseDistance,
            left: baseDistance
        },
        //7/15 tiles
        7: {
            num: 7,
            pos: 7,
            top: baseDistance,
            left: baseDistance * 2
        },
        //8/15 tiles
        8: {
            num: 8,
            pos: 8,
            top: baseDistance,
            left: baseDistance * 3
        },
        //END of second row
        //9/15 tiles
        9: {
            num: 9,
            pos: 9,
            top: baseDistance * 2,
            left: 0
        },
        //10/15 tiles
        10: {
            num: 10,
            pos: 10,
            top: baseDistance * 2,
            left: baseDistance
        },
        //11/15 tiles
        11: {
            num: 11,
            pos: 11,
            top: baseDistance * 2,
            left: baseDistance * 2
        },
        //12/15 tiles
        12: {
            num: 12,
            pos: 12,
            top: baseDistance * 2,
            left: baseDistance * 3
        },
        //END of third row
        //13/15 tiles
        13: {
            num: 13,
            pos: 13,
            top: baseDistance * 3,
            left: 0
        },
        //14/15 tiles
        14: {
            num: 14,
            pos: 14,
            top: baseDistance * 3,
            left: baseDistance
        },
        //14/15 tiles
        15: {
            num: 15,
            pos: 15,
            top: baseDistance * 3,
            left: baseDistance * 2
        },
        //empty space
        empty: {
            pos: 16,
            top: baseDistance * 3,
            left: baseDistance * 3
        }
    }//tileMap
    
    //creating an array which stores "num" tracking them by order of last moved
    var lastMoved = [];
    
    //defining the movement map to check the tiles neighbors based on its position
    function moveMap (pos){
        //returns the adjacent "pos" values according to the tile map
        /*format " return [top, left, right, bottom] "
                        1   2   3   4
                        5   6   7   8
                        9   10  11  12
                        13  14  15  16
        */
        if (pos == 16)
            return [12, 15];
        if (pos == 15)
            return [11, 14, 16];
        if (pos == 14)
            return [10, 13, 15];
        if (pos == 13)
            return [9, 14];
        if (pos == 12)
            return [8, 11, 16];
        if (pos == 11)
            return [7, 10, 12, 15];
        if (pos == 10)
            return [6, 9, 11, 14];
        if (pos == 9)
            return [5, 10, 13];
        if (pos == 8)
            return [4, 7, 12];
        if (pos == 7)
            return [3, 6, 8, 11];
        if (pos == 6)
            return [2, 5, 7, 10];
        if (pos == 5)
            return [1, 6, 9];
        if (pos == 4)
            return [3, 8];
        if (pos == 3)
            return [2, 4, 7];
        if (pos == 2)
            return [1, 3, 6];
        if (pos == 1)
            return [2, 5];
    }//moveMap
    
    //intializing the play are based on the tileMap
    document.querySelector('#shufflebutton').addEventListener('click', shuffle, true);
    //storing all the puzzlepiece elements within a var called tiles
    var tiles = document.querySelectorAll('.puzzlepiece');
    //setting the delay for the setTimeout function
    var delay = -50;
    //iterating throught the tiles array, adding event listeners for each and indentifying each
    for (var i = 0; i < tiles.length; i++){
        //adding an event listener to each element of the tiles array
        tiles[i].addEventListener('click', tileAction, true);
        //getting the ID number of each tile
        var tileID = tiles[i].innerHTML;
        //increasing the delay for each tile intiated
        delay += 50;
        //calling setInterval to run the init() function every delay ms
        setTimeout(init, delay, tiles[i]);
        
        //setting up the proper alignment of the image for each tile
        var x = (i%4)*100;
        var y = Math.floor(i/4)*100;
        var posX = x.toString();
        var posY = y.toString();
        //tiles[i].style.left = posX + "px";
        //tiles[i].style.top = posY + "px";
        tiles[i].style.backgroundPosition = "-" + posX + "px " + "-" + posY + "px";
    }//for
    
    function highlightMovableTile(tile){
        if (tileMovable(tiles[tile])){
            document.getElementByClassName("puzzlepiece").onmouseover = function() {mouseOver()};
        }
    }
    //init function that sets up indivdual tiles
    function init(tile){
        //getting the ID number of the tile to intiate
        var tileID = tile.innerHTML;
        //setting the movement variables in the x and y axis
        var xMove = parentX * (tileMap[tileID].left/100);
        var yMove = parentX * (tileMap[tileID].top/100);
        //creating the translation command to pass into webkit
        var tString = "translateX(" + xMove + "px) " + "translateY(" + yMove + "px)";
        tile.style.webkitTransform = tString;
    }//init
    
    //tileAction function that defines the response to user clicking on a tile
    function tileAction(event){
        //getting the ID number of the tile that is the "target" of the event
        var tileNum = event.target.innerHTML;
        //calling the movement function on the "target" of the event
        move(event.target);
        //calling the solution function to check if the puzzle has been solved
        if (solution()){
            window.alert("Congratulations! Puzzled Solved!");
        }
    }//tileAction
    
    //move function that moves tile to the empty spot, returns error message otherwise
    function move(tile, recordMoved = true){
        //getting the ID numebr of the tile that is trying to move
        var tileNum = tile.innerHTML;
        
        //checking if the tile can be moved (touching empty and directly perpendicular)
        if (!tileMovable(tileNum)){
            console.log("Tile " + tileNum + "cannot move.");
            return;
        }//if
        
        //pushing the current tile into the lastMoved array
        if(recordMoved == true){
            if(lastMoved.length >= 3){
                if(lastMoved[lastMoved.length-1] != lastMoved[lastMoved.length-3]){
                    lastMoved.push(tileNum);
                }//if
                else{
                    lastMoved.push(tileNum)
                }//else
            }//if
        }//if
        
        //swapping the position of the empty tile with the "target" tile
        //getting the tile above the empty tile
        var eTop = tileMap.empty.top;
        //getting the tile left of the empty tile
        var eLeft = tileMap.empty.left;
        //getting the positon of the empty tile
        var ePos = tileMap.empty.pos;
        //setting the tile on top of the empty tile to be the tile above "target"
        tileMap.empty.top = tileMap[tileNum].top;
        //setting the tile to the left of the empty tile to be the tile left of "target"
        tileMap.empty.left = tileMap[tileNum].left;
        //setting the position of the empty tile to be the position of "target"
        tileMap.empty.pos = tileMap[tileNum].pos;
        
        //setting the movement variables in the x and y axis for the empty tile
        var xMove = parentX * (eLeft/100);
        var yMove = parentX * (eTop/100);
        
        //creating the translation command to pass into webkit
        var tString = "translateX(" + xMove + "px) " + "translateY(" + yMove + "px)";
        tile.style.webkitTransform = tString;
        
        //swapping the position of the "target" tile with the empty tile
        tileMap[tileNum].top = eTop;
        tileMap[tileNum].left = eLeft;
        tileMap[tileNum].pos = ePos;
        
    }//move
    
    //tileMovable function determines whether the tile can move
    function tileMovable(tileNum){
        //getting the tile object that corresponds to tileNum
        var targetTile = tileMap[tileNum];
        //getting the tile object that is empty tile
        var emptyTile = tileMap.empty;
        //getting an array of movable tiles from the tile map
        var movableTiles = moveMap(emptyTile.pos);
        
        //if the targetTile is an element of the movableTiles array
        if (movableTiles.includes(targetTile.pos)){
            return true;
        } else {
            return false;
        }
    }//tileMovable
    
    //solution function returns true or false based on whether the puzzle has been solved
    function solution(){
        //if the empty tile is not in the last position
        if(tileMap.empty.pos !== 16){
            return false;
        }
        
        //iterating through tileMap, focusing on key
        for (var key in tileMap){
            if((key != 1) && (key != "empty")){
                if(tileMap[key].pos < tileMap[key-1].pos){
                    return false;
                }//if
            }//if
        }//for
        
        //if the puzzle is solved, reset lastMoved and return true
        lastMoved = [];
        return true;
    }//solution
    
    //shuffle function shuffles the tiles of the board to be solved
    shuffleTimeouts = [];
    function shuffle(){
        //clearTimers(solveTimeouts);
        //getting all the tiles, storing in an array "puzzleTiles"
        var puzzleTiles = document.querySelectorAll('.puzzlepiece');
        //setting the delay for shuffling the tiles
        var delay = 200;
        //calling the recursive function that controls the shuffling loop
        shuffleLoop();
        
        //
        var shuffleCounter = 0;
        while (shuffleCounter < 20){
            delay += 200;
            shuffleTimeouts.push(setTimeout(shuffleLoop, delay));
            shuffleCounter++;
        }//while
    }//shuffle
    
    var lastShuffled;
    //function shuffleLoop controls looping through hte tiles array and shuffling their pos
    function shuffleLoop(){
        //getting the positon of the empty tile
        var ePos = tileMap.empty.pos;
        //getting the movement map for the empty tile (at its current position)
        var sTiles = moveMap(ePos);
        //finding a random position for the tile to go to
        var tilePos = sTiles[Math.floor(Math.floor(Math.random()*sTiles.length))];
        //initiating a var that will store the tile object of the tile being moved
        var locatedTile;
        //iterating through all tiles and setting the first available tiles position to tilePos (must be able to actually make the movement)
        for(var i = 1; i <= 15; i++){
            if(tileMap[i].pos == tilePos){
                var targetTileNum = tileMap[i].num;
                locatedTile = tiles[targetTileNum - 1];
            }//if
        }//for
        //if the target Tile was not the last shuffled tile, move it
        if (lastShuffled != targetTileNum){
            move(locatedTile);
            lastShuffled = targetTileNum;
        }//if
        else{
            shuffleLoop();
        }//else
    }//shuffleLoop
}//puzzle