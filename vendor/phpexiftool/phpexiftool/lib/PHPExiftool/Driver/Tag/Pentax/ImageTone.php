<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Pentax;

use PHPExiftool\Driver\AbstractTag;

class ImageTone extends AbstractTag
{

    protected $Id = 79;

    protected $Name = 'ImageTone';

    protected $FullName = 'Pentax::Main';

    protected $GroupName = 'Pentax';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Pentax';

    protected $g2 = 'Camera';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'Image Tone';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Natural',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'Bright',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'Portrait',
        ),
        3 => array(
            'Id' => 3,
            'Label' => 'Landscape',
        ),
        4 => array(
            'Id' => 4,
            'Label' => 'Vibrant',
        ),
        5 => array(
            'Id' => 5,
            'Label' => 'Monochrome',
        ),
        6 => array(
            'Id' => 6,
            'Label' => 'Muted',
        ),
        7 => array(
            'Id' => 7,
            'Label' => 'Reversal Film',
        ),
        8 => array(
            'Id' => 8,
            'Label' => 'Bleach Bypass',
        ),
        9 => array(
            'Id' => 9,
            'Label' => 'Radiant',
        ),
    );

}
