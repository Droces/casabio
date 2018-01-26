// var gulp = require('gulp');

'use strict';

var gulp = require('gulp');
var sass = require('gulp-sass');
var sourcemaps = require('gulp-sourcemaps');
var compass = require('gulp-compass');

// Type: gulp
gulp.task('default', function() {
  // place code for your default task here
});

// Type: gulp sass
gulp.task('sass', function () {
  return gulp.src('./sass/**.scss')
    .pipe(sourcemaps.init())
    .pipe(sass().on('error', sass.logError))
    .pipe(sourcemaps.write('/sourcemaps'))
    .pipe(gulp.dest('./css'))
  ;
});


// Type: gulp sass:watch
gulp.task('sass:watch', function () {
  gulp.watch('./sass/**/*.scss', ['sass']);
});

// Type: gulp watch
gulp.task('watch', function () {
  gulp.watch('./sass/**/*.scss', ['sass']);
});
