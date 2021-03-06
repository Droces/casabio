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

class MultiSelectorPlaybackMode extends AbstractTag
{

    protected $Id = 'mixed';

    protected $Name = 'MultiSelectorPlaybackMode';

    protected $FullName = 'mixed';

    protected $GroupName = 'NikonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'NikonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'Multi Selector Playback Mode';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Thumbnail On/Off',
        ),
        1 => array(
            'Id' => 16,
            'Label' => 'View Histograms',
        ),
        2 => array(
            'Id' => 32,
            'Label' => 'Zoom On/Off',
        ),
        3 => array(
            'Id' => 48,
            'Label' => 'Choose Folder',
        ),
        4 => array(
            'Id' => 0,
            'Label' => 'Thumbnail On/Off',
        ),
        5 => array(
            'Id' => 1,
            'Label' => 'View Histograms',
        ),
        6 => array(
            'Id' => 2,
            'Label' => 'Zoom On/Off',
        ),
        7 => array(
            'Id' => 0,
            'Label' => 'Thumbnail On/Off',
        ),
        8 => array(
            'Id' => 16,
            'Label' => 'View Histograms',
        ),
        9 => array(
            'Id' => 32,
            'Label' => 'Zoom On/Off',
        ),
        10 => array(
            'Id' => 48,
            'Label' => 'Choose Folder',
        ),
    );

}
