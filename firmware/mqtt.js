// [] Como funcionan los events
// [] Como funcionan las funciones flecha en este codigo


const mqtt = require('mqtt');
const options = {
    clientId: 'myclient',
    Username: 'ferxxo',
    Password: 'jesus200'
};

const client = mqtt.connect('192.168.9.107', options);

client.on('connect', () => {
    console.log(`Is client connected: ${client.connected}`);

    // subscribe to a topic
    client.subscribe(topic);
});

// receive a message from the subscribed topic
client.on('message',(topic, message) => {
    console.log(`message: ${message}, topic: ${topic}`);
});

// error handling
client.on('error',(error) => {
    console.error(error);
    process.exit(1);
});