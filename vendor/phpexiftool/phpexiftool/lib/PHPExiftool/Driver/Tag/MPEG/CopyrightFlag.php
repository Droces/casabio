<?php

/*
 * This file is part of PHPExifTool.
 *
 * (c) 2012 Romain Neutron <imprec@gmail.com>
 *
 * For the full copyright and license information, please view the LICENSE
 * file that was distributed with this source code.
 */

namespace PHPExiftool\Driver\Tag\MPEG;

use PHPExiftool\Driver\AbstractTag;

class CopyrightFlag extends AbstractTag
{

    protected $Id = 'Bit28';

    protected $Name = 'CopyrightFlag';

    protected $FullName = 'MPEG::Audio';

    protected $GroupName = 'MPEG';

    protected $g0 = 'MPEG';

    protected $g1 = 'MPEG';

    protected $g2 = 'Audio';

    protected $Type = '?';

    protected $Writable = false;

    protected $Description = 'Copyright Flag';

    protected $Values = array(
        0 => array(
            'Id' => 0,
            'Label' => False,
        ),
        1 => array(
            'Id' => 1,
            'Label' => True,
        ),
    );

}
