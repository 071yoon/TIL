var express = require('express');
var router = express.Router();

var mysqlDB = require('../mysql_db');

router.get('/', function (req, res, next) {
    res.render('my_page');
});

router.post('/', function (req, res, next) {

	var userId = req.body['userId'];

    mysqlDB.query('select name, tot_cred, dept_name from student where id=?',[userId], function (err, rows, fields){
		if (!err) {                         //오류가 없으면 웹 페이지에 값 출력
            if (rows[0]!=undefined) {       //row가 존재하면 회원정보 출력
                var name=rows[0]['name'];
                var credit=rows[0]['tot_cred'];
                var dept=rows[0]['dept_name'];
                //리소스 보냄
                res.send(name+'님 환영합니다. <hr><br>' +
                    '이름 :'+name+'<br>'+
                    '학점 :'+credit+'<br>'+
                    '단과대 :'+dept+'<br>'
                    );
            } else {                    
                res.send('회원 정보가 없습니다');
            }

        } else {                        //오류가 있으면 오류코드 출력
            res.send('error : ' + err);
        }
    });
});


module.exports = router;

