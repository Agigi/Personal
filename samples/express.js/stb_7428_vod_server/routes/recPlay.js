
/*
 * GET home page.
 */

exports.index = function(req, res){
  console.log("RecordingID: " + req.params.RecordingID);
  
  var movie = "Yif-Magic.mp4";
  switch (req.params.RecordingID + "") {
  case "1800000101":
    movie = "avengers-tlr1_h1080p.mov";
	break;
  case "1900000201":
    movie = "battleship-tlr2_h1080p.mov";
	break;
  case "6500000601":
    movie = "batman_begins_1080p.mov";
	break;
  }
  
  res.sendfile('./public/video/' + movie);
};
