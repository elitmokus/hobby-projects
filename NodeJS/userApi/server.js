var express = require('express'),
	app = express(),
	port = process.env.PORT || 3000,
	mongoose = require('mongoose'),
	User = require('./src/models/userListModel'),
	Address = require('./src/models/addressModel'),
	bodyParser = require('body-parser');

mongoose.Promise = global.Promise;
mongoose.connect('mongodb://localhost/Userdb');

app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());

var routes = require('./src/routes/userListRoutes');
routes(app);

app.listen(port);

console.log('user management RESTful API server started on: ' + port);