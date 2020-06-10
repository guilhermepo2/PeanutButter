pong = {
    assets = {
        [0] = { type="texture", id="pong-ball", file="./assets/pong/fancy-ball.png" },
        [1] = { type="texture", id="pong-court", file="./assets/pong/fancy-court.png" },
        [2] = { type="texture", id="pong-paddle-grey", file="./assets/pong/fancy-paddle-grey.png" },
        [3] = { type="texture", id="pong-paddle-green", file="./assets/pong/fancy-paddle-green.png" },
        [4] = { type="texture", id="pong-paddle-blue", file="./assets/pong/fancy-paddle-blue.png" },
        [5] = { type="font", id="charriot-font", file="./assets/fonts/charriot.ttf", fontSize = 14 },
    },
    entities = {
        [0] = {
            name = "CourtBackground",
            layer = 0,
            components = {
                transform = {
                    position = { x = 0.0, y = 0.0 },
                    rotation = { x = 0.0, y = 0.0 },
                    scale = { x = 1.0, y = 1.0 }
                },
                sprite = {
                    texture = "pong-court",
                    size = { x = 800.0, y = 600.0 }
                }
            }
        }
    }
}