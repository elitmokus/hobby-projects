'use strict';

var mongoose = require('mongoose'),
  User = mongoose.model('Users'),
  Address = mongoose.model('Address');

exports.list_all_users = function(req, res) {
  User.find({}, function(err, user) {
    if (err)
      res.send(err);
    res.json(user);
  });
};

exports.create_a_user = function(req, res) {
  var new_user = new User(req.body);
  new_user.save(function(err, user) {
    if (err)
      res.send(err);
    res.json(user);
  });
};

exports.read_a_user = function(req, res) {
  User.findById(req.params.userId, function(err, user) {
    if (err)
      res.send(err);
    res.json(user);
  });
};

exports.update_a_user = function(req, res) {
  User.findOneAndUpdate({_id: req.params.userId}, req.body, {new: true}, function(err, user) {
    if (err)
      res.send(err);
    res.json(user);
  });
};


exports.delete_a_user = function(req, res) {
  User.remove({
    _id: req.params.userId
  }, function(err, user) {
    if (err)
      res.send(err);
    res.json({ message: 'User successfully deleted' });
  });
};


/*
exports.read_a_users_addresses = function(req, res) {
  // TODO
}

exports.add_a_users_address = function(reg, res) {
  // TODO
}

exports.delete_a_users_address = function(req, res) {
  // TODO
}
*/

exports.read_address = function(req, res) {
  Address.findById(req.params.addressId, function(err, address) {
    if (err)
      res.send(err);
    res.json(address);
  });
};

exports.create_address = function(req, res) {
  var new_address = new Address(req.body);
  new_address.save(function(err, address) {
    if (err)
      res.send(err);
    res.json(address);
  });
};

exports.delete_address = function(req, res) {
  Address.remove({
    _id: req.params.addressId
  }, function(err, address) {
    if (err)
      res.send(err);
    res.json({ message: 'Address successfully deleted' });
  });
};