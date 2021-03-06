<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\NikonCustom;

use PHPExiftool\Driver\AbstractTag;

class ShootingInfoMonitorOffTime extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'ShootingInfoMonitorOffTime';

    protected $FullName = 'mixed';

    protected $GroupName = 'NikonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'NikonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'Shooting Info Monitor Off Time';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => '4 s',
        ),
        1 => array(
            'Id' => 8,
            'Label' => '10 s',
        ),
        2 => array(
            'Id' => 16,
            'Label' => '20 s',
        ),
        3 => array(
            'Id' => 24,
            'Label' => '1 min',
        ),
        4 => array(
            'Id' => 32,
            'Label' => '5 min',
        ),
        5 => array(
            'Id' => 40,
            'Label' => '10 min',
        ),
        6 => array(
            'Id' => 0,
            'Label' => '4 s',
        ),
        7 => array(
            'Id' => 4,
            'Label' => '10 s',
        ),
        8 => array(
            'Id' => 8,
            'Label' => '20 s',
        ),
        9 => array(
            'Id' => 12,
            'Label' => '1 min',
        ),
        10 => array(
            'Id' => 16,
            'Label' => '5 min',
        ),
        11 => array(
            'Id' => 20,
            'Label' => '10 min',
        ),
        12 => array(
            'Id' => 0,
            'Label' => '4 s',
        ),
        13 => array(
            'Id' => 4,
            'Label' => '10 s',
        ),
        14 => array(
            'Id' => 8,
            'Label' => '20 s',
        ),
        15 => array(
            'Id' => 12,
            'Label' => '1 min',
        ),
        16 => array(
            'Id' => 16,
            'Label' => '5 min',
        ),
        17 => array(
            'Id' => 20,
            'Label' => '10 min',
        ),
    );

}
