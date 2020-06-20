'use strict';

var mongoose = require('mongoose');

const Users = mongoose.model(
  "Users",
  new mongoose.Schema({
    name: String,
    email: String,
    addresses: []
  })
);

module.exports = Users;