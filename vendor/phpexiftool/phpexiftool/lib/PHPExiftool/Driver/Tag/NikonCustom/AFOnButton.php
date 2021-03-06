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

class AFOnButton extends AbstractTag
{

    protected $Id = '3.1';

    protected $Name = 'AFOnButton';

    protected $FullName = 'NikonCustom::SettingsD3';

    protected $GroupName = 'NikonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'NikonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'AF On Button';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'AF On',
        ),
        1 => array(
            'Id' => 1,
            'Label' => 'AE/AF Lock',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'AE Lock Only',
        ),
        3 => array(
            'Id' => 3,
            'Label' => 'AE Lock (reset on release)',
        ),
        4 => array(
            'Id' => 4,
            'Label' => 'AE Lock (hold)',
        ),
        5 => array(
            'Id' => 5,
            'Label' => 'AF Lock Only',
        ),
    );

}
