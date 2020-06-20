'use strict';

var mongoose = require('mongoose');

const Address = mongoose.model(
  "Address",
  new mongoose.Schema({
  	country: String,
    city: String,
    street: String,
    numberOfHouse: Number
  })
);

module.exports = Address;
