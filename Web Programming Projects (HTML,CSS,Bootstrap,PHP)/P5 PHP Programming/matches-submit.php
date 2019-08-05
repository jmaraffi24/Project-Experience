<!DOCTYPE html>
<html>

    <!-- shared page top HTML -->

    <head>
        <title>Match</title>

        <meta charset="utf-8" />

        <!-- instructor-provided CSS and JavaScript links; do not modify -->
        <link href="heart.gif" type="image/gif" rel="shortcut icon" />
        <link href="match.css" type="text/css" rel="stylesheet" />

        <script src="http://ajax.googleapis.com/ajax/libs/prototype/1.7.0.0/prototype.js" type="text/javascript"></script>
    </head>

    <body>
        <div id="bannerarea">
            <img src="match.png" alt="banner logo" /> <br />
        </div>

        <!-- your HTML output follows -->

        <?php
        //All the user information will be stored in these variables

        $userName = $_GET["name"];
        $userGender;
        $userAge;
        $userPersonality;
        $userOS;
        $userMinage;
        $userMaxage;

        $myfile = fopen("singles.txt", "r") or die("Unable to open file!");
        $singles = array();
        $count;

        // Stores all the information in singles.txt into an array called singles and is parsed by new lines. Its basically fstream.
        while(!feof($myfile)) {
            $singles[$count] = fgets($myfile);
            $count++;
        }


        /*
               This will store all the names, genders, ages, compatible age ranges, favorite OS systems, and personality types
               into their own seperate arrays. This allows us to compare each of the requirements for matches. For
               example, if we are trying to find a match for the first person in the singles.txt list and we find a match,
               it will return all the values at the same index for each of the arrays. The requirements are as
               follows:
               1. The opposite gender of the given user
               2. Of compatible ages; that is, each person is between the other's minimum and maximum ages,inclusive
               3. Has the same favorite operating system as this user
               4. Shares at least one personality type letter in common at the same index in each string.For example, ISTP and ESFP have 2 in common (S, P)
            */

        $name = array(); //all array lengths will be number of people in singles.txt minus the person we are trying to find matches for
        $gender = array();
        $age = array();
        $minage = array();
        $maxage = array();
        $OS = array();
        $personality = array();
        for ($x = 0; $x < count($singles); $x++){
            $myArray = explode(',', $singles[$x]); //explode turns a string into an array with a seperator. In this case, the seperator is ","
            if ($userName == $myArray[0]){ //finds the user's information from singles.txt and stores it into these variables
                $userGender = $myArray[1];
                $userAge = $myArray[2];
                $userPersonality = $myArray[3];
                $userOS = $myArray[4];
                $userMinage = $myArray[5];
                $userMaxage = $myArray[6];
                continue;
            }

            $name[$x] = $myArray[0];
            $gender[$x] = $myArray[1];
            $age[$x] = $myArray[2];
            $personality[$x] = $myArray[3];
            $OS[$x] = $myArray[4];
            $minage[$x] = $myArray[5];
            $maxage[$x] = $myArray[6];
        }

        $matchName = array();
        $matchGender = array();
        $matchAge = array();
        $matchPersonality = array();
        $matchOS = array();
        $matches = array($matchName, $matchGender, $matchAge, $matchPersonality, $matchOS); //This is where the matches information will be stored and is a 2-dimensional array

        $count = 0;
        // The logic to find the matches. I seperated the requirements by a few if statements for readability purposes. When a match is found, their name, gender, age, personality, and OS information are stored in the first available slot in each array in $matches. This means that if there is only 1 match, then their name will be stored in $matches[0][0], their gender in $matches[1][0], and so forth. If there was a second match, then that match's name will be stored in $matches[0][1], their gender in $matches[1][1], and so forth //
        for ($x = 0; $x < count($singles); $x++){ //iterates through every single person in singles array for a match
            /*echo $userGender;//user gender
            echo $userOS;
            echo $gender[$x];//all genders
            echo $OS[$x];
            echo "\r\n
            echo $singles[$x];*/
            if (strcasecmp($userGender, $gender[$x]) != 0 && strcasecmp($userOS, $OS[$x]) == 0){ //Genders must be opposite and operating system preferances must be the same
                if ($userAge <= $maxage[$x] && $userAge >= $minage[$x]){ //user must be in the preferred age range of the match
                    if ($age[$x] <= $userMaxage && $age[$x] >= $userMinage){ //match must be in the preffered age range of the user
                        if (strcasecmp(substr($userPersonality, 0, 1), substr($personality[$x], 0, 1))==0 || strcasecmp(substr($userPersonality, 1, 1), substr($personality[$x], 1, 1))==0
                            || strcasecmp(substr($userPersonality, 2, 1), substr($personality[$x], 2, 1))==0 || strcasecmp(substr($userPersonality, 3, 1), substr($personality[$x], 3, 1))==0){ //Personality test
                            $matches[0][$count] = $name[$x];
                            $matches[1][$count] = $gender[$x];
                            $matches[2][$count] = $age[$x];
                            $matches[3][$count] = $personality[$x];
                            $matches[4][$count] = $OS[$x];
                            $count++;                            
                        }
                    }
                }
            }
            else{
                continue;
            }
        }
        fclose($myfile);


        //opening the images file
        $imgfile = fopen("singles.txt", "r") or die("Unable to open file!");
        echo"<div>";//outermost div which contains everything under matches
        echo"<strong>Matches for $userName </strong>";//"title" section which displays the username of the person looking for matches
        for($x = 0; $x < count($matches[0]); $x++){//for loop makes sure the html is populated for all matches in the matches array
            //variable which stores the changes image names
            $imgname = $matches[0][$x];
            //replacing white spaces with underscores to match the naming conventions of the image files
            $imgname = str_replace(" ", "_" ,$imgname);
            //appending .jpg to the end of the image name to open
            $imgname .= ".jpg";
            //making all characters lower case
            $imgname = strtolower($imgname);
            echo"<div class=\"match\">";//contains all information on the matches
            echo"<p><img src=\"images/Images/" .$imgname. "\">" .$matches[0][$x]. "</p>";//div that contains the name of the match
            echo"<ul>";//unordered list which contains all the match information
            echo"<li><strong> Gender: </strong>" .$matches[1][$x]. "</li>";//first list element, gender 
            echo"<li><strong> Age: </strong>" .$matches[2][$x]. "</li>";//second list element, age
            echo"<li><strong> Type: </strong>" .$matches[3][$x]. "</li>";//third list element, type
            echo"<li><strong> OS: </strong>" .$matches[4][$x]. "</li>";//third list element, type
            echo"</ul>";//end of the unordered list
            echo"</div>";//end of the div that contains all the amtches
        }
        echo"</div>";
        ?><!-- END OF PHP SCRIPT-->

        <!-- shared page bottom HTML -->
        <div>
            <p>
                This page is for single nerds to meet and date each other!  Type in your personal information and wait for the geek love to begin!  Thank you for using our site.
            </p>

            <p>
                Results and page (C) Copyright Match Inc.
            </p>

            <ul>
                <li>
                    <a href="index.php">
                        <img src="back.gif" alt="icon" />
                        Back to front page
                    </a>
                </li>
            </ul>
        </div>

    </body>
</html>
