var createError = require('http-errors');
var express = require('express');
var path = require('path');
var cookieParser = require('cookie-parser');
var logger = require('morgan');

var indexRouter = require('./routes/index');
var usersRouter = require('./routes/users');

var mysqlDB=require('./mysql_db')
mysqlDB.connect();

var app = express();


// view engine setup
app.set('views', path.join(__dirname, 'views'));
app.set('view engine', 'ejs');

app.use(logger('dev'));
app.use(express.json());
app.use(express.urlencoded({ extended: false }));
app.use(cookieParser());
app.use(express.static(path.join(__dirname, 'public')));

app.use('/', indexRouter);
app.use('/users', usersRouter);

var show_all_data_router=require('./routes/show_all_data');
app.use('/show_all_data', show_all_data_router);

var my_page_router = require('./routes/my_page');
app.use('/my_page', my_page_router);

var takes_router = require('./routes/takes');
app.use('/takes', takes_router);

var library_router = require('./routes/library');
app.use('/library', library_router);

var all_books_router = require('./routes/all_books');
app.use('/all_books', all_books_router);

var my_books_router = require('./routes/my_books');
app.use('/my_books', my_books_router);

var donate_router = require('./routes/donate');
app.use('/donate', donate_router);

var borrow_router = require('./routes/borrow');
app.use('/borrow', borrow_router);

var extend_router = require('./routes/extend');
app.use('/extend', extend_router);

var return_router = require('./routes/return');
app.use('/return', return_router);

// catch 404 and forward to error handler
app.use(function(req, res, next) {
  next(createError(404));
});

// error handler
app.use(function(err, req, res, next) {
  // set locals, only providing error in development
  res.locals.message = err.message;
  res.locals.error = req.app.get('env') === 'development' ? err : {};

  // render the error page
  res.status(err.status || 500);
  res.render('error');
});

module.exports = app;
