const net = require('net');
const https = require('http');
const express = require('express');
const cors = require('cors');

const app = express();
app.use(cors());

// This is TCP
// We receive data on this port
const receivingPort = 8080;
// We serve data on this port
// This is HTTP
const servingPort = 4000;

var peopleCount = 0;

app.listen(servingPort, () => {
  console.log(`Serving data on ${servingPort}`);
});

app.get('/count', (req, res, next) => {
  res.json({
    count: peopleCount,
  });
});

const receivingServer = new net.Server();

receivingServer.listen(receivingPort, () => {
  console.log(`Server listening on ${receivingPort}`);
});

receivingServer.on('connection', (socket) => {
  console.log('A new connection has been established');

  socket.write('Hello');

  socket.on('data', (chunk) => {
    console.log(`Data received ${chunk}`);
    if (isInteger(chunk)) {
      peopleCount = chunk.toString();
    }
  });

  socket.on('exit', (_chunk) => {
    console.log('Client has exited');
  });

  socket.on('error', (error) => {
    console.log(`An error has occurred ${error}`);
  });
});

function isInteger(value) {
  return /^\d+$/.test(value);
}
