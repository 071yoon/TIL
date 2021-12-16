var mysql = require("mysql");

var connection=mysql.createConnection({
	host: "mm.konkuk.ac.kr",
	post: 3306,
	user: "user_201713025",
	password: "201713025",
	database: "user_201713025"
})

module.exports=connection;