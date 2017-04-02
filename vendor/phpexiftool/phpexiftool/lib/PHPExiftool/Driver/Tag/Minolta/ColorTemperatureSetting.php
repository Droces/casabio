<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\Minolta;

use PHPExiftool\Driver\AbstractTag;

class ColorTemperatureSetting extends AbstractTag
{

    protected $Id = 37;

    protected $Name = 'ColorTemperatureSetting';

    protected $FullName = 'Minolta::CameraSettingsA100';

    protected $GroupName = 'Minolta';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'Minolta';

    protected $g2 = 'Camera';

    protected $Type = 'int16u';

    protected $Writable = true;

    protected $Description = 'Color Temperature Setting';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => 'Temperature',
        ),
        2 => array(
            'Id' => 2,
            'Label' => 'Color Filter',
        ),
    );

}
