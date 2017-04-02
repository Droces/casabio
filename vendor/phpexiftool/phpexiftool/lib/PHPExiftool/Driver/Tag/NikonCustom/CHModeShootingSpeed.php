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

class CHModeShootingSpeed extends AbstractTag
{

    protected $Id = '10.3';

    protected $Name = 'CHModeShootingSpeed';

    protected $FullName = 'NikonCustom::SettingsD3';

    protected $GroupName = 'NikonCustom';

    protected $g0 = 'MakerNotes';

    protected $g1 = 'NikonCustom';

    protected $g2 = 'Camera';

    protected $Type = 'int8u';

    protected $Writable = true;

    protected $Description = 'CH Mode Shooting Speed';

    protected $flag_Permanent = true;

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => '9 fps',
        ),
        16 => array(
            'Id' => 16,
            'Label' => '10 fps',
        ),
        32 => array(
            'Id' => 32,
            'Label' => '11 fps',
        ),
    );

}
